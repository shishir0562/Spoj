#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int> graph[21000];
int color[21000];
bool check(int n, int e){
	int i, u, v;
	bool flag=false;
	memset(color, 0, sizeof(color));
	for(i=0;i<n&&flag==false;++i){
		if(color[i]==0){
			color[i]=1;
			queue<int> q;
			q.push(i);
			while(!q.empty()&&flag==false){
				u=q.front();
				q.pop();
				int sz=graph[u].size();
				for(int j=0;j<sz;++j){
					v=graph[u][j];
					if(color[u]==color[v]){
						flag=true;
						break;
					}
					if(color[v]==0){
						if(color[u]==1){
							color[v]=-1;
							q.push(v);
						}
						else
						if(color[u]==-1){
							color[v]=1;
							q.push(v);
						}
					}
				}
			}
		}
	}
	return flag;
}
int main() {
	// your code goes here
	int t, v1, v2, n, e, i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		scanf("%d",&e);
		while(e--){
			scanf("%d",&v1);
			scanf("%d",&v2);
			graph[v1-1].push_back(v2-1);
			graph[v2-1].push_back(v1-1);
		}
		if(check(n, e)) printf("Scenario #%d:\nSuspicious bugs found!\n",i);
		else printf("Scenario #%d:\nNo suspicious bugs found!\n",i);
		//for(int j=0;j<n;++j) cout << color[j] << " ";
		for(int j=0;j<2000;++j) graph[j].clear();
	}
	return 0;
} 
