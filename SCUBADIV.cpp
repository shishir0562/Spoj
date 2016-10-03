#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define inf 100000000
using namespace std;
int w[1000];
int ox[1000];
int ni[1000];
int tab1[22][80];
int tab2[22][80];
/*int find(int oxy, int nitro, int n){
	if(n==0){
		if(oxy>0||nitro>0) return inf;
		else return 0;
	}
	if(oxy<=0&&nitro<=0) return 0;
	return min(w[n-1]+find(oxy-ox[n-1], nitro-ni[n-1], n-1), find(oxy, nitro, n-1));
}*/
int find(int oxy, int nitro, int num){
	int c1, c2, o, n;
	for(int i=0;i<=oxy;++i){
		for(int j=0;j<=nitro;++j)
		tab1[i][j]=inf;
	}
	tab1[0][0]=0;
	for(int k=1;k<=num;++k){
		for(int i=0;i<=oxy;++i){
			for(int j=0;j<=nitro;++j){
				if(i==0&&j==0) tab2[i][j]=0;
				c1=tab1[i][j];
				o=i-ox[k-1];
				n=j-ni[k-1];
				if(o<0) o=0;
				if(n<0) n=0;
				c2=w[k-1]+tab1[o][n];
				tab2[i][j]=min(c2, c1);
			}
		}
		for(int i=0;i<=oxy;++i){
			for(int j=0;j<=nitro;++j)
			tab1[i][j]=tab2[i][j];
		}
	}
	return tab2[oxy][nitro];
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		int oxy, nitro, n;
		scanf("%d",&oxy);
		scanf("%d",&nitro);
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&ox[i]);
			scanf("%d",&ni[i]);
			scanf("%d",&w[i]);
		}
		printf("%d\n", find(oxy, nitro, n));
	}
	return 0;
} 
