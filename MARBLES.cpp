#include <iostream>
long long int tab[3][1000001];
using namespace std;
long long int cal(long long int n, long long int r){
		if(r>n-r)
		r=n-r;
		long long int ans=1;
		for(long long int i=0;i<r;++i){
			ans=ans*(n-i)/(i+1);
		}
		return ans;
}
int main() {
	// your code goes here
	int t;
	cin >>t;
	while(t--){
		long long int n, k;
		cin >> n >> k;
		cout <<cal(n-1,k-1)<< "\n";
	}
	return 0;
} 
