#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node {
	int price;
	int fun;
}party;
/*int find(party p[], int budget, int n){
	if(n==0)
	return 0;
	if(n!=0&&budget==0)
	return 0;
	if(budget<p[n-1].price)
	return find(p, budget, n-1);
	else
	return max(p[n-1].fun+find(p, budget-p[n-1].price,n-1),find(p, budget, n-1));
}*/
void find(party p[], int budget, int n){
	int tab[n+1][budget+1];
	for(int i=0;i<=budget;++i)
	tab[0][i]=0;
	for(int i=0;i<=n;++i)
	tab[i][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=budget;++j){
			tab[i][j]=tab[i-1][j];
			if(j>=p[i-1].price)
			tab[i][j]=max(p[i-1].fun+tab[i-1][j-p[i-1].price],tab[i-1][j]);
		}
	}
	int max_fun=tab[n][budget];
	int max_cost=0;
	for(int i=budget;i>=0;--i){
		if(tab[n][i]!=tab[n][i-1]){
			max_cost=i;
			break;
		}
	}
	cout << max_cost << " " << max_fun << "\n";
}
int main() {
	// your code goes here
	int budget,n;
	while(1){
		cin >> budget >> n;
		if(budget==0&&n==0)
		break;
		else{
			party p[n];
			int i=0,x,y;
			while(i<n){
				cin >> x >> y;
				p[i].price=x;
				p[i].fun=y;
				i++;
			}
			find(p, budget, n);
		}
	}
	return 0;
} 
