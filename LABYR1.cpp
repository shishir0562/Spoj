#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
struct node{
	char c;
};
struct p{
	int x;
	int y;
};
bool isSafe(int x, int y, int r, int c){
	if(x>=0&&x<r&&y>=0&&y<c)
	return true;
	else return false;
}
int bfs(struct node *s, int r, int c, int *src, int *dest){
	bool flag=true;
	int x,y,i,j;
	bool visited[r][c];
	int dist[r][c];
	for(i=0;i<r;++i){
		for(j=0;j<c;++j){
			visited[i][j]=false;
			if((s+c*i+j)->c=='.')
			dist[i][j]=0;
			else
			dist[i][j]=INT_MIN;
		}
	}
	i=*src,j=*dest;
	dist[i][j]=0;
	queue<struct p> que;
	struct p temp;
	temp.x=i;
	temp.y=j;
	//cout << i << j;
	que.push(temp);
	while(!que.empty()){
		temp=que.front();
		que.pop();
		x=temp.x;
		y=temp.y;
		int x1,y1;
		visited[x][y]=true;
		if(isSafe(x-1,y,r,c)){
			x1=x-1,y1=y;
			if((s+c*x1+y1)->c=='.'&&visited[x1][y1]==false){
				visited[x1][y1]=true;
				dist[x1][y1]=1+dist[x][y];
				temp.x=x1;
				temp.y=y1;
				que.push(temp);
			}
		}
		if(isSafe(x+1,y,r,c)){
			x1=x+1,y1=y;
			if((s+c*x1+y1)->c=='.'&&visited[x1][y1]==false){
				visited[x1][y1]=true;
				dist[x1][y1]=1+dist[x][y];
				temp.x=x1;
				temp.y=y1;
				que.push(temp);
			}
		}
		if(isSafe(x,y-1,r,c)){
			x1=x,y1=y-1;
			if((s+c*x1+y1)->c=='.'&&visited[x1][y1]==false){
				visited[x1][y1]=true;
				dist[x1][y1]=1+dist[x][y];
				temp.x=x1;
				temp.y=y1;
				que.push(temp);
			}
		}
		if(isSafe(x,y+1,r,c)){
			x1=x,y1=y+1;
			if((s+c*x1+y1)->c=='.'&&visited[x1][y1]==false){
				visited[x1][y1]=true;
				dist[x1][y1]=1+dist[x][y];
				temp.x=x1;
				temp.y=y1;
				que.push(temp);
			}
		}
	}
	int max=0;
	for(i=0;i<r;++i){
		for(j=0;j<c;++j){
			if(dist[i][j]>max){
				max=dist[i][j];
				*src=i;
				*dest=j;
			}
		}
	}
	return max;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int c, r,x,y;
		char ch;
		cin >> c >> r;
		struct node s[r][c];
		bool flag=true;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				cin >> ch;
				s[i][j].c=ch;
				if(flag&&s[i][j].c=='.'){
					x=i;
					y=j;
					flag=false;
				}
			}
		}
		int path=bfs((struct node*)s, r,c,&x,&y);
		path=bfs((struct node*)s, r,c,&x,&y);
		cout << "Maximum rope length is " << path << "." << "\n";
	}
	return 0;
} 
