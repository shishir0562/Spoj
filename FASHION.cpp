#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n],b[n];
		for(int i=0;i<n;++i) cin >> a[i];
		for(int i=0;i<n;++i) cin >> b[i];
		sort(a,a+n);
		sort(b,b+n);
		long long int count=0;
		for(int i=0;i<n;++i){
			count=count+(a[i]*b[i]);
		}
		cout << count << "\n";
	}
	return 0;
} 
