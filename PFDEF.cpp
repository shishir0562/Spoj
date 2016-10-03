#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[102];
int indegree[102];
int main() {
	// your code goes here
	for(int i=0;i<102;++i) indegree[i]=0;
	int n, m, j;
	cin >> n >> m;
	int u, v;
	for(int i=0;i<m;++i){
		cin >> u;
		cin >> j;
		for(int k=1;k<=j;++k){
			cin >> v;
			graph[v].push_back(u);
		}
		indegree[u]+=j;
	}
	//for(int i=1;i<=n;++i) cout << indegree[i] << " ";
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=1;i<=n;++i){
        if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
        u=q.top();
        cout << u << " ";
        q.pop();
        int sz=graph[u].size();
        for(int v=0;v<sz;++v){
            indegree[graph[u][v]]--;
            if(indegree[graph[u][v]]==0)
                q.push(graph[u][v]);
        }
	}
	return 0;
}
 
