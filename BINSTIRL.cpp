#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		int n, m;
		scanf("%d",&n);
		scanf("%d",&m);
		if(n==0&&m==0) printf("%d\n", 1);
		else
		if(n==0||m==0) printf("%d\n", 0);
		else{
			if(((n-m)&(m-1)/2)==0) printf("%d\n" ,1);
			else printf("%d\n", 0);
		}
		
	}
	return 0;
} 
