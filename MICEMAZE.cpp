#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;
int main() {
	// your code goes here
	int n, exit, time, m, u, v, w;
	scanf("%d",&n);
	scanf("%d",&exit);
	scanf("%d",&time);
	scanf("%d",&m);
	vector<pii> graph[n+1];
	for(int i=0;i<m;++i){
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&w);
		graph[v].push_back(pii(w, u));
	}
	graph[0].push_back(pii(0, exit));
	priority_queue<pii, vector<pii>, greater<pii> >q;
	bool visited[n+1];
	int path[n+1];
	for(int i=0;i<=n;++i){
		visited[i]=false;
		path[i]=1000000000;
	}
	pii temp;
	path[0]=0;
	q.push(pii(0, 0));
	while(!q.empty()){
		temp=q.top();
		q.pop();
		u=temp.second;
		w=temp.first;
		visited[u]=true;
		int sz=graph[u].size();
		for(int i=0;i<sz;++i){
			v=graph[u][i].second;
			w=graph[u][i].first;
			if(visited[v]==false&&path[v]>w+path[u]){
				path[v]=w+path[u];
				q.push(pii(path[v], v));
			}
		}
	}
	int c=0;
	for(int i=1;i<=n;++i){
		if(path[i]<=time) c++;
	}
	printf("%d",c);
	return 0;
}
 
