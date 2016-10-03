#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs(string n, string m, int len){
	int tab[2][len+1],i,j;
	for(int i=0;i<=len;++i) tab[0][i]=0;
	//for(int i=0;i<=len;++i) tab[0][i]=0;
	tab[1][0]=0;
	for(i=1;i<=len;++i){
		for(j=1;j<=len;++j){
			if(n[i-1]==m[j-1])
			tab[1][j]=1+tab[0][j-1];
			else
			tab[1][j]=max(tab[0][j],tab[1][j-1]);
			tab[0][j-1]=tab[1][j-1];
		}
		tab[0][j-1]=tab[1][j-1];
	}
	return tab[1][len];
}
int main() {
	// your code goes here
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		int len=s.size();
		string s_rev(len,'0');
		for(int i=0;i<len;++i)
		s_rev[i]=s[len-i-1];
		//s_rev=s.reverse(len);
		//cout << s_rev.size();
		int lc=lcs(s,s_rev,len);
		//cout << s_rev << " ";
		cout << len-lc << "\n";
	}
	return 0;
} 
