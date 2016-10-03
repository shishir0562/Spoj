#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
bool check(long long int n){
	if(n==0||n==1||n==2)
	return true;
	double x=sqrt(n);
	if((x-(double)floor(x))==0)
	return true;
	else
	{
		long long int y=floor(sqrt(n/2)),temp;
		long long int z=floor(sqrt(n));
		while(z>=y){
			temp=n-(z*z);
			x=sqrt(temp);
			if((x-(double)floor(x))==0){
				return true;
			}
			else{
				z--;
			}
		}
	}
	return false;
}
int main(void) {
	// your code goes here
	int c;
	cin >> c;
	while(c--){
		long long int n;
		cin >> n;
		if(check(n))
		cout << "Yes\n";
		else
		cout << "No\n";
	}
	return 0;
} 
