#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void update(long long int tree[], long long int a, long long int b, long long int p, long long int q, long long int v, long long int lazy[], int index){
	if(lazy[index]!=0){
		tree[index]+=(b-a+1)*lazy[index];
		if(a!=b){
			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];
		}
		lazy[index]=0;
	}
	if(q<a||p>b||a>b)
	return;
	if(p<=a&&q>=b){
		tree[index]+=(b-a+1)*v;
		if(a!=b){
			lazy[2*index+1]+=v;
			lazy[2*index+2]+=v;
		}
		return;
	}
	update(tree,a,(a+b)/2,p,q,v,lazy,2*index+1);
	update(tree,1+(a+b)/2,b,p,q,v,lazy,2*index+2);
	tree[index]=tree[2*index+1]+tree[2*index+2];
}
long long int query(long long int tree[], long long int a, long long int b, long long int p, long long int q,long long int lazy[], int index){
	if(q<a||p>b||a>b)
	return 0;
	if(lazy[index]!=0){
		tree[index]+=(b-a+1)*lazy[index];
		if(a!=b){
			//int v=tree[index]/(b-a+1)
			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];
		}
		lazy[index]=0;
	}
	if(p<=a&&q>=b){
		return tree[index];
	}
	long long int x=query(tree, a,(a+b)/2,p,q,lazy,index*2+1);
	long long int y=query(tree,(a+b)/2+1,b,p,q,lazy,index*2+2);
	return x+y;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		long long int n,c;
		cin >> n >> c;
		long long int t,p,q,v;
		long long int x=2*(long long int)(pow(2,(int)ceil(log2(n))))+1;
		long long int tree[x],lazy[x];
		for(long long int i=0;i<x;++i){
			tree[i]=0;
			lazy[i]=0;
		}
		while(c--){
		cin >> t;
		if(t==0){
			cin >> p >> q >> v;
			update(tree,0,n-1,p-1,q-1,v,lazy,0);
			/*for(long long int i=0;i<x;++i)
			cout << tree[i] << " ";*/
		}
		else{
			cin >> p >> q;
			cout << query(tree,0,n-1,p-1,q-1,lazy,0) << "\n";
		}
		}
		/*for(long long int i=0;i<x;++i)
			cout << tree[i] << " ";*/
	}
	return 0;
} 
