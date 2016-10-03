#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
typedef struct node Node;
typedef long long int ll;
struct node {
	ll h; 
	ll w;
	ll d;
};
Node box[90];
ll mem[90];
bool comp(Node a, Node b){
	return ((a.w*a.d)<(b.w*b.d))?true:false;
}
int main() {
	// your code goes here
	ll n, h,d, w;
	while(1){
		scanf("%lld",&n);
		if(n==0) return 0;
		Node temp;
		ll j=0;
		for(ll i=0;i<n;++i){
			scanf("%lld",&h);
			scanf("%lld",&w);
			scanf("%lld",&d);
			temp.h=h;
			temp.w=w;
			temp.d=d;
			box[j]=temp;
			j++;
			swap(temp.h, temp.w);
			box[j]=temp;
			j++;
			swap(temp.h, temp.d);
			box[j]=temp;
			j++;
		}
		sort(box, box+3*n, comp);
		//for(int i=0;i<(3*n);++i) cout << a[i].h << " " << a[i].w << " " << a[i].d << "\n";
		n=3*n;
		memset(mem, 0, sizeof(mem));
		mem[0]=box[0].h;
		ll h;
		for(ll i=1;i<n;++i){
			h=0;
			for(ll j=i-1;j>=0;--j){
				if(((box[i].w*box[i].d)>(box[j].w*box[j].d))&&((box[i].w>box[j].w&&box[i].d>box[j].d)||(box[i].w>box[j].d&&box[i].d>box[j].w))){
					h=max(h, mem[j]);
				}
			}
			mem[i]=box[i].h+h;
		}
		ll maxi=0;
		for(ll i=0;i<n;++i){
			maxi=max(maxi, mem[i]);
		}
		printf("%lld\n",maxi);
	}
	return 0;
} 
