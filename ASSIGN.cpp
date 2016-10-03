#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
long long int dp[(1<<20)];
int c(int n){
	int count=0;
	while(n){
		if(n&1) count++;
		n>>=1;
	}
	return count;
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int val[n][n];
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&val[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0]=1;
		int MAX=(1<<n), N;
		for(int mask=0;mask<MAX-1;++mask){
			N=c(mask);
			for(int i=0;i<n;++i){
				if(val[N][i]==1&&(mask&(1<<i))==0){
					dp[mask|(1<<i)]+=dp[mask];
				}
			}
		}
		printf("%lld\n", dp[MAX-1]);
	}
	return 0;
} 
