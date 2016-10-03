#include <iostream>
#include <cmath>
#include <cstdio>
#define INPUT(x) scanf("%d",&x);
using namespace std;
 
int main() {
	// your code goes here
	int n,k;
	int c=1;
	while(1){
		//scanf("%d",&n);
		INPUT(n);
		if(n!=-1){
			int co[n+1];
			int i=0,j;
			while(i<n+1){
				//scanf("%d",&co[i]);
				INPUT(co[i]);
				i++;
			}
			//scanf("%d",&k);
			INPUT(k);
			int x;
			printf("Case %d:\n",c);
			for(i=0;i<k;++i){
				//scanf("%d",&x);
				INPUT(x);
				long long int po=pow(x,n),sum=0;
				for(j=0;j<n;++j){
					sum=sum+(co[j]*po);
					if(po!=0)
					po=po/x;
				}
				sum+=co[j];
				printf("%lld\n",sum);
			}
			c++;
		}
		else
		break;
	}
	return 0;
} 
