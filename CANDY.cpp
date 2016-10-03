#include <iostream>
using namespace std;
typedef long long int ll;
int main() {
	// your code goes here
	ll n;
	cin >> n;
	while(n!=-1){
		ll i=0;
	ll a[n];
	ll sum=0;
	while(i<n){
		cin >> a[i];
		sum+=a[i];
		i++;
	}
	if(sum%n==0){
		ll m=sum/n;
		ll count=0;
		i=0;
		while(i<n){
			if(a[i]<m)
			count+=m-a[i];
			i++;
		}
		cout << count << "\n";
	}
	else
	cout << -1 << "\n";
	cin >> n;
	}
	return 0;
} 
