#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 100000+2
using namespace std;
vector<int> graph[MAX];
int dp[MAX][2];
bool vs[MAX][2];
int find(int u, bool cover, int par){
	int &res=dp[u][cover];
	if(vs[u][cover]) return res;
	vs[u][cover]=true;
	int sz=graph[u].size();
	for(int i=0;i<sz;++i){
		if(graph[u][i]!=par){
			if(cover) res+=min(find(graph[u][i], 1, u), find(graph[u][i], 0, u));
			else res+=find(graph[u][i], 1, u);
		}
	}
	res+=cover;
	return res;
}
int main() {
	// your code goes here
	int n, u, v;
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		scanf("%d",&u);
		scanf("%d",&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int ans =1;
    if(n!=1)
    ans=min(find(1, 1, -1), find(1, 0, -1));
    printf("%d",ans);
	return 0;
}
 
