#include <iostream>
using namespace std;
void find(int *w, int n){
	int u,v;
	for(int i=0;i<n;++i){
		u=i;
		for(int j=i+1;j<n;++j){
			v=j;
			bool flag=false;
			for(int k=0;k<n;++k){
				if(k!=u&&k!=v&&*(w+n*u+v)==(*(w+n*u+k)+*(w+n*k+v))){
					flag=true;
				}
			}
			if(!flag)
			cout << u+1 << " " << v+1 << "\n";
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int w[n][n];
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin >> w[i][j];
			}
		}
		find((int*)w,n);
	}
	return 0;
} 
