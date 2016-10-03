#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	cin >> n;
	long long int tab;
	tab=1;
	for(int i=2;i<=n;++i){
		int j=floor(sqrt(i)),count=0;
		for(int k=1;k<=j;++k){
			if(i%k==0)
			count++;
		}
		tab+=count;
	}
	/*for(int i=0;i<=n;++i)
	cout << tab[i] << " ";*/
	cout << tab;
	return 0;
} 
