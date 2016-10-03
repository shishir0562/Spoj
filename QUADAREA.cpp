#include <stdio.h>
#include <math.h>
int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		double a,b,c,d;
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		double s=(a+b+c+d)/2;
		double area=sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2lf\n",area);
	}
	return 0;
}
 
