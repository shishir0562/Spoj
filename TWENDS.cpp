#include <iostream>
#include <string.h>
#include <algorithm>
#define inf 100000000
using namespace std;
int sum[1001];
int a[1001];
int dp[1001][1001];
/*int find(int beg, int end){
    if(beg>end) return 0;
    if(beg+1==end) return abs(a[beg]-a[end]);
    int m1, m2;
    // chooses beg
	if(a[beg+1]>=a[end]){
		m1=a[beg]-a[beg+1];
		m1+=find(beg+2, end);
	}
	else{
		m1=a[beg]-a[end];
		m1+=find(beg+1, end-1);
	}
	// chooses end
	if(a[beg]>=a[end-1]){
		m2=a[end]-a[beg];
		m2+=find(beg+1, end-1);
	}
	else{
		m2=a[end]-a[end-1];
		m2+=find(beg, end-2);
	}
	return max(m1,m2);
}*/
int find(int beg, int end){
	if(beg>end) return 0;
	if(beg+1==end){
		dp[beg][end]=abs(a[beg]-a[end]);
		return dp[beg][end];
	}
	int m1, m2, c;
	// chooses beg
	if(a[beg+1]>=a[end]){
		m1=a[beg]-a[beg+1];
		if(dp[beg+2][end]==inf){
			c=find(beg+2, end);
			dp[beg+2][end]=c;
		}
		m1+=dp[beg+2][end];
	}
	else{
		m1=a[beg]-a[end];
		if(dp[beg+1][end-1]==inf){
			c=find(beg+1, end-1);
			dp[beg+1][end-1]=c;
		} 
		m1+=dp[beg+1][end-1];
	}
	// chooses end
	if(a[beg]>=a[end-1]){
		m2=a[end]-a[beg];
		if(dp[beg+1][end-1]==inf){
			c=find(beg+1, end-1);
			dp[beg+1][end-1]=c;
		}
		m2+=dp[beg+1][end-1];
	}
	else{
		m2=a[end]-a[end-1];
		if(dp[beg][end-2]==inf){
			c=find(beg, end-2);
			dp[beg][end-2]=c;
		} 
		m2+=dp[beg][end-2];
	}
	dp[beg][end]=max(m1, m2);
	return dp[beg][end];
}
int main() {
	// your code goes here
	int n, k=1;
	while(1){
		cin >> n;
		if(n==0) break;
		for(int i=0;i<1001;++i){
			for(int j=0;j<1001;++j){
				dp[i][j]=inf;
			}
		}
		for(int i=0;i<n;++i) cin >> a[i];
		cout << "In game " << k << ", the greedy strategy might lose by as many as "<<find(0, n-1)<< " points." << "\n";
		/*for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}*/
		k++;
	}
	return 0;
} 
