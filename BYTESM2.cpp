#include <iostream>
#include <algorithm>
using namespace std;
int maximum(int x, int y, int z){
	if(x>y){
		if(x>z)
		return x;
		else
		return z;
	}
	else
	{
		if(y>z)
		return y;
		else
		return z;
	}
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int h,w;
		cin >> h >> w;
		int a[h][w];
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j)
			cin >> a[i][j];
		}
		int tab[h][w];
		for(int i=0;i<w;++i)
		tab[h-1][i]=a[h-1][i];
		for(int i=h-2;i>=0;--i){
			for(int j=0;j<w;++j){
				if(j==0){
					tab[i][j]=a[i][j]+max(tab[i+1][j+1],tab[i+1][j]);
				}
				else
				if(j==w-1){
					tab[i][j]=a[i][j]+max(tab[i+1][j-1], tab[i+1][j]);
				}
				else{
					tab[i][j]=a[i][j]+maximum(tab[i+1][j-1], tab[i+1][j], tab[i+1][j+1]);
				}
			}
		}
		int maxi=-1;
		for(int i=0;i<w;++i)
		maxi=max(maxi,tab[0][i]);
		cout << maxi << "\n";
	}
	return 0;
} 
