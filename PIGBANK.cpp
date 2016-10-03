#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef struct node {
	long long int m;
	long long int w;
}node;
/*int find(node a[], int n, int weight){
	if(weight==0)
	return 0;
	if(weight!=0&&n==0)
	return INT_MAX;
	if(a[n-1].w>weight)
	return find(a, n-1, weight);
	else
	return min(a[n-1].m+find(a,n,weight-a[n-1].w),find(a,n-1,weight));
}*/
long long int find(node a[], long long int n, long long int weight){
	//int tab[n+1][weight+1];
	long long int tab[3][weight+1],x,y;
	tab[0][0]=0;
	tab[1][0]=0;
	tab[2][0]=0;
	for(long long int i=1;i<=weight;++i)
	tab[0][i]=20000000;
	for(long long int i=1;i<=n;++i){
		if(i%2==1){
			x=0,y=2;
		}
		else{
			x=2,y=0;
		}
		for(int j=1;j<=weight;++j){
			tab[1][j]=tab[x][j];
			if(a[i-1].w<=j)
			tab[1][j]=min(a[i-1].m+tab[1][j-a[i-1].w],tab[x][j]);
			tab[y][j]=tab[1][j];
		}
	}
	if(tab[1][weight]>=20000000){
	cout << "This is impossible.";
	return -1;
	}
	else
	return tab[1][weight];
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		long long int e,f,m,w,i=0;
		cin >> e >> f;
		int n;
		cin >> n;
		node a[n];
		while(i<n){
			cin >> m >> w;
			a[i].m=m;
			a[i].w=w;
			i++;
		}
		long long int fi=find(a, n, f-e);
		if(fi==-1)
		cout << "\n";
		else
		cout << "The minimum amount of money in the piggy-bank is " << fi << "." << "\n";
	}
	return 0;
} 
