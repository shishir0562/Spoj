#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 100001
#define inf 1000000000;
#define pii pair<int,int>
map<string, int> hmap;
vector< pii > G[MAX];
int visited[MAX],path[MAX];
int main() {
	// your code goes here
	int t,n,e,u,v,w,r,src,dest,sz;
	char s[20];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%s%d",s,&e);
			hmap[s]=i;
			//scanf("%s",&e);
			for(int j=1;j<=e;++j){
				scanf("%d%d",&v,&w);
				G[i].push_back(pii(w,v));
			}
		}
		scanf("%d",&r);
		while(r--){
			scanf("%s",s);
			src=hmap[s];
			scanf("%s",s);
			dest=hmap[s];
			priority_queue<pii, vector<pii>, greater<pii> >q;
			for(int i=1;i<=n;++i){
				visited[i]=0;
				path[i]=inf;
			}
			path[src]=0;
			q.push(pii(0,src));
			while(!q.empty()){
				u=q.top().second;
				w=q.top().first;
				q.pop();
				if(visited[u]) continue;
				sz=G[u].size();
				for(int j=0;j<sz;++j){
					v=G[u][j].second;
					w=G[u][j].first;
					if(!visited[v]&&path[u]+w<path[v]){
						path[v]=path[u]+w;
						q.push(pii(path[v],v));
					}
				}
				visited[u]=1;
				if(u==dest) break;
			}
			printf("%d\n",path[dest]);
		}
		for(int i=1;i<=n;++i) G[i].clear();
		hmap.clear();
	}
	return 0;
} 
