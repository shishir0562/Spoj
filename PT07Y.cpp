#include <iostream>
#include <queue>
using namespace std;
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
bool isCycle(struct Graph *g, bool *visited){
	int v=g->V,u;
	int parent[v];
	struct AdjListNode *node;
	for(int i=0;i<v;++i)
	parent[i]=-1;
	queue<int> que;
	que.push(0);
	visited[0]=true;
	bool flag=true;
	while((!que.empty())&&flag){
		u=que.front();
		que.pop();
		node=g->array[u].head;
		while(node!=NULL){
			if(visited[node->dest]){
				if(node->dest!=parent[u]){
					flag=false;
					break;
				}
			}
			else{
				visited[node->dest]=true;
				parent[node->dest]=u;
				que.push(node->dest);
			}
			node=node->next;
		}
	}
	if(flag){
	return false;
	}
	else
	return true;
}
bool check(struct Graph *graph){
	int v=graph->V;
	bool visited[v];
	for(int i=0;i<v;++i)
	visited[i]=false;
	if(isCycle(graph,visited))
	return false;
	for(int i=0;i<v;++i){
		if(visited[i]==false){
		return false;
		}
	}
	return true;
}
int main() {
	// your code goes here
	int n,m;
	cin >> n >> m;
	struct Graph *g=createGraph(n);
	int u,v;
	for(int i=0;i<m;++i){
		cin >> u >> v;
		addEdge(g,u-1,v-1);
	}
	if(check(g))
	cout << "YES";
	else
	cout << "NO";
	return 0;
} 
