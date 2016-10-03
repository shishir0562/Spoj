#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long int ll;
map<ll,ll> h;
ll cal(ll n){
	ll r=h[n];
	if(r!=0)
	return r;
	if(n==0)
	return 0;
	r= max(n,cal(n/2)+cal(n/3)+cal(n/4));
	h[n]=r;
	return r;
}
/*ll cal(ll n){
	ll tab[n+1];
	tab[0]=0;
	tab[1]=1;
	tab[2]=2;
	tab[3]=3;
	for(ll i=4;i<=n;++i){
		ll val=i/2+i/3+i/4;
		if(i>val)
		tab[i]=i;
		else
		tab[i]=max(val,tab[i/2]+tab[i/3]+tab[i/4]);
	}
	return tab[n];
}*/
int main() {
	ll n;
	while(scanf("%lld",&n)!=EOF){
			cout << cal(n) << "\n";
	}
	return 0;
} 
