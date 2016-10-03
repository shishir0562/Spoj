#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> agr;
vector<int> tom;
int getPoint(){
	int n=agr.size();
	int m=tom.size();
	int i, j;
	int tab[2][m+1];
	tab[1][0]=0;
	for(i=0;i<m+1;++i) tab[0][i]=0;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(agr[i-1]==tom[j-1])
			tab[1][j]=1+tab[0][j-1];
			else
			tab[1][j]=max(tab[0][j], tab[1][j-1]);
			tab[0][j-1]=tab[1][j-1];
		}
		tab[0][j-1]=tab[1][j-1];
	}
	return tab[1][m];
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		int n, point=-1;
		while(1){
			scanf("%d",&n);
			if(n==0) break;
			agr.push_back(n);
		}
		while(1){
			scanf("%d",&n);
			if(n==0) break;
			tom.push_back(n);
			while(1){
				scanf("%d",&n);
				if(n==0) break;
				else tom.push_back(n);
			}
			point=max(point, getPoint());
			tom.clear();
		}
		printf("%d\n", point);
		agr.clear();
	}
	return 0;
} 
