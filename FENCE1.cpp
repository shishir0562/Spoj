#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
 
int main() {
	// your code goes here
	int l;
	while(1){
		scanf("%d",&l);
		if(l==0)
		break;
		else{
			double x=pow(l,2);
			double y=2*3.14159;
			cout << setprecision(2) << fixed << x/y << "\n";
		}
	}
	return 0;
} 
