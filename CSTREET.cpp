#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;
#define pii pair<int, int>
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int p,n,m, v, e, w;
		cin >> p;
		cin >> n ;
		cin >> m;
		vector<pair<int, int> > g[n];
		for(int i=0;i<m;++i){
			cin >> v >> e >> w;
			g[v-1].push_back(pii(w, e-1));
			g[e-1].push_back(pii(w, v-1));
		}
		/*for(int i=0;i<n;++i){
			for(int j=0;j<g[i].size();++j){
				cout << g[i][j].second << " "<< g[i][j].first << " ";
			}
			cout << "\n";
		}*/
		bool visited[n];
		int dist[n];
		for(int i=0;i<n;++i){
			visited[i]=false;
			dist[i]=INT_MAX;
		}
		dist[0]=0;
		priority_queue<pii, vector<pii>, greater<pii> >q;
		q.push(pii(0, 0));
		int tot=0;
		while(!q.empty()){
			int u, w, v;
			u=q.top().second;
			q.pop();
			visited[u]=true;
			int sz=g[u].size();
			for(int i=0;i<sz;++i){
				v=g[u][i].second;
				w=g[u][i].first;
				if(visited[v]==false&&w<dist[v]){
					dist[v]=w;
					q.push(pii(dist[v],v));
				}
			}
		}
		for(int i=0;i<n;++i){
			tot+=dist[i];
		}
		cout << tot*p << "\n";
	}
	return 0;
} 
