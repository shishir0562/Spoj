#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int grid[11][11];
int tab[(1<<12)][12];
int count(int n){
	int c=0;
	while(n){
		if(n&1) c++;
		n>>=1;
	}
	return c;
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		int n=11;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&grid[i][j]);
			}
		}
		int MAX=(1<<n), N;
		memset(tab, -1000000, sizeof(tab));
		for(int i=0;i<=12;++i) tab[0][i]=0;
		for(int i=0;i<=MAX-1;++i) tab[i][0]=0;
		for(int mask=0;mask<MAX-1;++mask){
			N=count(mask);
			for(int i=0;i<n;++i){
				if((mask&(1<<i))==0&&grid[N][i]!=0){
					tab[mask|(1<<i)][N+1]=max(tab[mask|(1<<i)][N+1], tab[mask][N]+grid[N][i]);
				}
			}
		}
		int maxi=-1;
		for(int i=1;i<=MAX-1;++i)
		maxi=max(tab[MAX-1][i], maxi);
		printf("%d\n",maxi);
	}
	return 0;
}
 
