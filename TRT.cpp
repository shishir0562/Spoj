#include <iostream>
#include <algorithm>
using namespace std;
long long int tab[2000][2000];
long long int find(int a[], int beg, int end, int age){
	if(beg>end){
		tab[beg][end]=0;
		return 0;
	}
	if(beg==end){
		tab[beg][end]=a[beg]*age;
		return a[beg]*age;
	}
	else{
		long long int x=0,y=0;
		if(tab[beg+1][end]!=0)
		x=a[beg]*age+tab[beg+1][end];
		if(tab[beg][end-1]!=0)
		y=a[end]*age+tab[beg][end-1];
		if(x!=0&&y!=0)
		tab[beg][end]=max(x,y);
		else
		if(x!=0&&y==0)
		tab[beg][end]=max(x, a[end]*age+find(a, beg, end-1, age+1));
		else
		if(x==0&&y!=0)
		tab[beg][end]=max(a[beg]*age+find(a, beg+1, end, age+1),y);
		else
		tab[beg][end]=max(a[beg]*age+find(a, beg+1, end, age+1), a[end]*age+find(a, beg, end-1, age+1));
	}
	return tab[beg][end];
}
int main() {
	// your code goes here
	int n;
	cin >> n;
	int v[n];
	int i=0;
	while(i<n){
		cin >> v[i];
		i++;
	}
	cout << find(v,0, n-1,1);
	return 0;
} 
