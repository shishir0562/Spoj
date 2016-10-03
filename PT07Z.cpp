#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dist[10000];
struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};
struct AdjList
{
    struct AdjListNode *head;
};
struct Graph
{
    int V;
    struct AdjList *array;
};
struct Graph* createGraph(int v)
{
    struct Graph *graph;
    int i;
    graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=v;
    graph->array=(struct AdjList*)malloc(v*sizeof(struct AdjList));
    for(i=0;i<v;++i)
        graph->array[i].head=NULL;
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    struct AdjListNode *node=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    /*src to dest*/
    node->next=graph->array[src].head;
    node->dest=dest;
    graph->array[src].head=node;
    /*dest to src*/
    node=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    node->dest=src;
    node->next=graph->array[dest].head;
    graph->array[dest].head=node;
}
int bfs(struct Graph *g, int src){
	for(int i=0;i<g->V;++i){
		dist[i]=-1;
	}
	queue<int> que;
	que.push(src);
	dist[src]=0;
	struct AdjListNode *node;
	int u;
	while(!que.empty()){
		u=que.front();
		que.pop();
		node=g->array[u].head;
		while(node!=NULL){
			if(dist[node->dest]==-1){
				dist[node->dest]=1+dist[u];
				que.push(node->dest);
			}
			node=node->next;
		}
	}
	int max_dist=dist[src],max_node=src;
	for(int i=0;i<g->V;++i){
		if(dist[i]>max_dist){
			max_dist=dist[i];
			max_node=i;
		}
	}
	return max_node;
}
int main() {
	// your code goes here
	int n,u,v;
	cin >> n;
	struct Graph *g=createGraph(n);
	for(int i=0;i<n-1;++i){
		cin >> u >> v;
		addEdge(g, u-1, v-1);
	}
	int node=bfs(g,0);
	node=bfs(g, node);
	cout << dist[node];
	return 0;
} 
