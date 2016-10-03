#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int mem[2001][2001];
/*int edist(string s1, string s2, int m, int n){
	if(m==0&&n==0)
	return 0;
	if(m==0)
	return n;
	if(n==0)
	return m;
	int c1=0,c2=0,c3=0,c4=0;
	c1=1+edist(s1, s2, m-1,n);
	c2=1+edist(s1, s2, m,n-1);
	if(s1[m-1]==s2[n-1]){
		c3=edist(s1, s2, m-1,n-1);
		return min(min(c1,c2),c3);
	}
	else{
		c4=1+edist(s1, s2, m-1, n-1);
		return min(min(c1, c2),c4);
	}
}*/
int edist(string s1, string s2, int m, int n){
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n;++j){
			if(i==0)
			mem[i][j]=j;
			else
			if(j==0)
			mem[i][j]=i;
			else
			if(s1[i-1]==s2[j-1])
			mem[i][j]=mem[i-1][j-1];
			else{
				mem[i][j]=1+min(min(mem[i][j-1],mem[i-1][j]),mem[i-1][j-1]);
			}
		}
	}
	return mem[m][n];
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		string s1,s2;
		cin >> s1;
		cin >> s2;
		int m=s1.size();
		int n=s2.size();
		cout << edist(s1, s2, m, n) << "\n";
	}
	return 0;
} 
