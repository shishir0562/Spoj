#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <cstdio>
#define MAX 10001
using namespace std;
//vector<int> graph[MAX];
//int pre[MAX];
//int post[MAX];
int parent[MAX];
bool vs[MAX];
//int count=0;
/*void DFS(int src){
	vs[src]=true;
	pre[src]=count;
	count++;
	int sz=graph[src].size();
	for(int i=0;i<sz;++i){
		if(vs[graph[src][i]]==false){
			parent[graph[src][i]]=src;
			DFS(graph[src][i]);
			post[graph[src][i]]=count;
			count++;
		}
	}
	post[src]=count;
}*/
/*bool checkAncestor(int u, int v){
	if((pre[u]<pre[v])&&(post[u]>post[v])) return true;
	else return false;
}*/
int findLCA(int u, int v){
	memset(vs, false, sizeof(vs));
	vs[u]=true;
	while(parent[u]!=u){
		vs[u]=true;
		u=parent[u];
	}
	vs[u]=true;
	while(vs[v]!=1){
		v=parent[v];
	}
	return v;
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		printf("Case %d:\n", k);
		//memset(vs, false, sizeof(vs));
		//memset(parent, 1, sizeof(parent));
		/*memset(post,0, sizeof(post));
		memset(pre, 0,sizeof(pre));*/
		int n, m, v, q, u;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) parent[i]=i;
		for(int i=1;i<=n;++i){
			scanf("%d",&m);
			for(int j=1;j<=m;++j){
				scanf("%d",&v);
				parent[v]=i;
				//graph[i].push_back(v);
				//graph[v].push_back(i);
			}
		}
		//DFS(1);
		//for(int i=1;i<=n;++i) cout << pre[i] << " " << post[i] << " ";
		scanf("%d",&q);
		for(int i=1;i<=q;++i){
			scanf("%d",&u);
			scanf("%d",&v);
			printf("%d\n", findLCA(u, v));
		}
	}
	return 0;
} 
