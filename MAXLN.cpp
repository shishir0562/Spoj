#include <stdio.h>
 
int main(void) {
	// your code goes here
	int t,i=1;
	scanf("%d",&t);
	while(t--){
		long long int r;
		scanf("%lld",&r);
		double s=(4*r*r)+0.25;
		printf("Case %d: %0.2lf\n",i,s);
		i++;
	}
	return 0;
}
 
