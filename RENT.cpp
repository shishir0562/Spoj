#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
typedef long long int ll;
using namespace std;
typedef struct node Node;
struct node{
	int st;
	int ft;
	int p;
};
Node order[10000];
ll dp[10001];
bool comp(Node a, Node b){
	return (a.ft<=b.ft)?true:false;
}
int search(int beg, int end, int key){
	while(beg<=end){
		int mid=(end-beg)/2+beg;
		if(order[mid].ft==key) return mid;
		else{
			if(order[mid].ft>key) mid=end-1;
			else
			if(mid==end||order[mid+1].ft>key) return mid;
			else beg=mid+1;
		}
	}
	return -1;
}
ll check(int n){
    ll maxi;
	dp[0]=order[0].p;
	for(int i=1;i<n;++i){
		int end=i-1, beg=0;
		maxi=0;
		/*while(beg<=end){
			int j=search(beg, end, order[i].st);
			if(j!=-1){
				maxi=max(maxi, dp[j]);
				end=j-1;
			}
			else break;
		}*/
		for(int j=i-1;j>=0;--j){
			if(order[j].ft<=order[i].st) maxi=max(maxi, dp[j]);
		}
		dp[i]=order[i].p+maxi;
	}
	maxi=0;
	for(int i=0;i<n;++i) maxi=max(maxi, dp[i]);
	return maxi;
}
ll find(int n){
	sort(order, order+n, comp);
	//for(int i=0;i<n;++i) cout << order[i].ft << " ";
	return check(n);
	//return 0;
}
int main() {
	// your code goes her
	int t;
	scanf("%d",&t);
	while(t--){
		Node temp;
		int st, ft, p;
	    int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&st);
			order[i].st=st;
			scanf("%d",&ft);
			order[i].ft=st+ft;
			scanf("%d",&p);
			order[i].p=p;
		}
		cout << find(n) << "\n";
		//for(int i=0;i<n;++i) cout << dp[i] << " ";
	}
	return 0;
}
 
