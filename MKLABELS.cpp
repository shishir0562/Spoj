#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	int i=1;
	while(1){
		cin >> n;
		if(n==0) break;
		else{
			if(n==1) cout << "Case "<<i<<", N = " <<n << ", # of different labelings = " <<1 << "\n";  
			else cout <<"Case "<<i<<", N = " <<n << ", # of different labelings = " << (int)pow(n,n-2) << "\n";  
			i++;
		}
	}
	return 0;
} 
