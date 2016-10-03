#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		long long int height[n];
		for(int i=0;i<n;++i) cin >> height[i];
		sort(height, height+n);
		//for(int i=0;i<n;++i) cout << height[i];
		long long int diff=height[k-1]-height[0];
		for(int i=1;i<=n-k;++i){
			diff=min(diff,height[i+k-1]-height[i]);
		}
		cout << diff << "\n";
	}
	return 0;
} 
