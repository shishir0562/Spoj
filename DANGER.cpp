#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int mem[100000000];
int main() {
	// your code goes here
	mem[1]=1;
	for(int i=2;i<=99000000;++i){
	mem[i]=mem[i-1]+2;
	if(mem[i]>i)
	mem[i]-=i;
	//cout << mem[i] << " ";
	}
	char s[5];
	while(1){
		scanf("%s",s);
		int n;
		n=((s[0]-48)*10+s[1]-48)*pow(10,s[3]-48);
		if(n!=0)
		cout << mem[n] << "\n";
		//cout << n;
		else
		break;
	}
	return 0;
} 
