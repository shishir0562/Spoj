#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// your code goes here
	long long int n;
	while(1){
		cin >> n;
		if(n==-1)
		break;
		else{
			if(n==1)
			cout << "Y\n";
			else
			if(n>1&&n<7)
			cout << "N\n";
			else
			if(n==7)
			cout << "Y\n";
			else{
				double x=(double)(n-1)/3;
				if((x-floor(x))==0){
					long long int y=(long long int)x;
					if(y%2==0){
						long long int i=floor(sqrt(y));
						if((i*(i+1))==y)
						cout << "Y\n";
						else
						cout << "N\n";
					}
					else cout << "N\n";
				}
				else cout << "N\n";
			}
		}
	}
	return 0;
} 
