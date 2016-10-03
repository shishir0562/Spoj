#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define inf 1000000000
typedef pair<int, int> pii;
vector<pii> g[10000];
bool visited[10000];
long long int cost[10000];
char name[11];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int v, e, dest, c;
        scanf("%d",&v);
        for(int i=0;i<v;++i){
            scanf("%s",name);
            scanf("%d",&e);
            for(int j=0;j<e;++j){
                scanf("%d",&dest);
                scanf("%d",&c);
                g[i].push_back(pii(c, dest-1));
                g[dest-1].push_back(pii(c, i));
            }
        }
        priority_queue<pii, vector<pii>, greater<pii> >q;
        for(int i=0;i<v;++i){
            visited[i]=false;
            cost[i]=inf;
        }
        pii temp;
        int sz, u, w;
        cost[0]=0;
        q.push(pii(0, 0));
        while(!q.empty()){
            temp=q.top();
            u=temp.second;
            w=temp.first;
            q.pop();
            visited[u]=true;
            sz=g[u].size();
            for(int i=0;i<sz;++i){
                int v;
                v=g[u][i].second;
                w=g[u][i].first;
                if(!visited[v]&&cost[v]>w){
                    cost[v]=w;
                    q.push(pii(cost[v], v));
                }
            }
        }
        long long int sum=0;
        for(int i=0;i<v;++i){
            sum+=cost[i];
        }
        for(int i=0;i<v;++i) g[i].clear();
        printf("%lld\n", sum);
    }
    return 0;
}
