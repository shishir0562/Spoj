#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define inf 1000000000
struct node {
	int w,x,y;
};
bool isSafe(int x, int y, int r, int c){
	if(x>=0&&x<r&&y>=0&&y<c) return true;
	else return false;
}
int main() {
	// your code goes here
	int c,r;
	char val;
	int neig[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
	while(1){
		scanf("%d%d",&c,&r);
		//cout << c << r;
		if(c!=0&&r!=0){
			char mat[r][c];
			pair<int, int> src, dest;
			for(int i=0;i<r;++i){
				scanf( "%*c" );
				for(int j=0;j<c;++j){
					scanf("%c",&val);
					if(val=='S'){
						src.first=i;
						src.second=j;
					}
					if(val=='D'){
						dest.first=i;
						dest.second=j;
					}
					mat[i][j]=val;
				}
			}
			/*for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					cout << mat[i][j] << " ";
				}
				cout << "\n";
			}*/
			int path[r][c];
			struct node temp;
			bool visited[r][c];
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					path[i][j]=inf;
					if(mat[i][j]=='X')
					visited[i][j]=true;
					else
					visited[i][j]=false;
				}
			}
			int x,y,vx,vy,w;
			path[src.first][src.second]=0;
			path[dest.first][dest.second]=0;
			queue<struct node> q;
			temp.w=0;
			temp.x=src.first;
			temp.y=src.second;
			q.push(temp);
			while(!q.empty()){
				temp=q.front();
				//cout << temp.w << "\n";
				q.pop();
				w=temp.w;
				x=temp.x;
				y=temp.y;
				//visited[x][y]=true;
				for(int i=0;i<4;++i){
					vx=x+neig[i][0];
					vy=y+neig[i][1];
					if(isSafe(vx,vy,r,c)&&visited[vx][vy]==false){
						w=mat[vx][vy]-48;
						if(path[x][y]+w<path[vx][vy]){
							path[vx][vy]=path[x][y]+w;
							temp.w=path[vx][vy];
							temp.x=vx;
							temp.y=vy;
							q.push(temp);
						}
					}
				}
			}
			x=dest.first;
			y=dest.second;
			int mini=inf;
			for(int i=0;i<4;++i){
				vx=x+neig[i][0];
				vy=y+neig[i][1];
				if(isSafe(vx,vy,r,c))
				mini=min(mini,path[vx][vy]);
			}
			printf("%d\n",mini);
		}
		else break;
	}
	return 0;
} 
