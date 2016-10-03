#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		long long int n,m;
		cin >> n >> m;
		if(n==m){
			if(n%2==0)
			cout << "L\n";
			else
			cout << "R\n";
		}
		else
		{
			if(n>m){
				if(m%2==0)
				cout << "U\n";
				else
				cout << "D\n";
			}
			else{
				if(n%2==0)
				cout << "L\n";
				else
				cout << "R\n";
			}
		}
	}
	return 0;
} 
