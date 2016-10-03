#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define pii pair<int, int>
using namespace std;
vector<pii> graph[50001];
long long int dist[50001];
bool visited[50001];
int find(int n, int src){
	memset(dist, -1, sizeof(dist));
	memset(visited, false, sizeof(visited));
	queue<pii> q;
	int u, v, w;
	q.push(pii(0, src));
	visited[src]=true;
	pii temp;
	dist[src]=0;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		u=temp.second;
		int sz=graph[u].size();
		for(int j=0;j<sz;++j){
			v=graph[u][j].second;
			w=graph[u][j].first;
			if(visited[v]==false){
				visited[v]=true;
				dist[v]=dist[u]+w;
				q.push(pii(dist[v], v));
			}
		}
	}
	int node=1;
	long long int maxi=dist[1];
	for(int i=2; i<=n;++i){
		if(dist[i]>=maxi){
			maxi=dist[i];
			node=i;
		}
	}
	return node;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int u, v, w;
		for(int i=1;i<=n-1;++i){
			cin >>u >> v >> w;
			graph[u].push_back(pii(w, v));
			graph[v].push_back(pii(w, u));
		}
		int node=find(n,1);
		node=find(n, node);
		cout << dist[node]<< "\n";
		for(int i=1;i<=n;++i){
			graph[i].clear();
		}
	}
	return 0;
} 
