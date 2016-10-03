#include <iostream>
using namespace std;
typedef long long int ll;
ll expo(ll a, ll b, ll mod){
	ll x=1;
	ll power=a%mod;
	while(b){
		if(b&1)
		x=(x*power)%mod;
		power=(power*power)%mod;
		b>>=1;
	}
	return x;
}
int main() {
	// your code goes here
	ll t;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		cout << expo(a,b,10) << "\n";
	}
	return 0;
} 
