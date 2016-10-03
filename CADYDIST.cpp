#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long int ll;
int main() {
	// your code goes here
	ll n;
	while(1){
		cin >> n;
		if(n==0)
		break;
		else{
			ll stu[n];
			ll price[n];
			ll i=0;
			while(i<n){
				cin >> stu[i];
				i++;
			}
			i=0;
			while(i<n){
				cin >> price[i];
				i++;
			}
			sort(stu,stu+n);
			sort(price,price+n);
			ll count=0;
			for(ll i=0;i<n;++i){
				count+=stu[i]*price[n-i-1];
			}
			cout << count << "\n";
		}
	}
	return 0;
} 
