#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <stdio.h>
int dist[182][182],visited[182][182],pix[182][182]; 
using namespace std;
struct pos{
	int x;
	int y;
};
bool isSafe(int x, int y, int n, int m){
	if(x>=0&&x<n&&y>=0&&y<m)
	return true;
	else return false;
}
void find(int n, int m,int src_x, int src_y){
	//bool visited[n][m];
	memset(visited, false, sizeof(visited));
	queue<struct pos> que;
	struct pos temp;
	temp.x=src_x;
	temp.y=src_y;
	visited[src_x][src_y]=true;
	que.push(temp);
	int x, y;
	while(!que.empty()){
		temp=que.front();
		que.pop();
		x=temp.x;
		y=temp.y;
		if(isSafe(x-1,y,n,m)&&pix[x-1][y]==0&&visited[x-1][y]==false){
			int u=x-1,v=y;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
		if(isSafe(x+1,y,n,m)&&pix[x+1][y]==0&&visited[x+1][y]==false){
			int u=x+1,v=y;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
		if(isSafe(x,y-1,n,m)&&pix[x][y-1]==0&&visited[x][y-1]==false){
			int u=x,v=y-1;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
		if(isSafe(x,y+1,n,m)&&pix[x][y+1]==0&&visited[x][y+1]==false){
			int u=x,v=y+1;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
		if(isSafe(x-1,y-1,n,m)&&pix[x-1][y-1]==0&&visited[x-1][y-1]==false){
			int u=x-1,v=y-1;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
		if(isSafe(x+1,y-1,n,m)&&pix[x+1][y-1]==0&&visited[x+1][y-1]==false){
			int u=x+1,v=y-1;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
		if(isSafe(x+1,y+1,n,m)&&pix[x+1][y+1]==0&&visited[x+1][y+1]==false){
			int u=x+1,v=y+1;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
		if(isSafe(x-1,y+1,n,m)&&pix[x-1][y+1]==0&&visited[x-1][y+1]==false){
			int u=x-1,v=y+1;
			temp.x=u;
			temp.y=v;
			visited[u][v]=true;
			int curr_dist=abs(src_x-u)+abs(src_y-v);
			if(dist[u][v]>curr_dist){
				dist[u][v]=curr_dist;
				que.push(temp);
			}
		}
	}
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<struct pos> vtr;
		struct pos temp;
		string s;
		for(int i=0;i<n;++i){
			cin >> s;
			for(int j=0;j<m;++j){
				pix[i][j]=s[j]-'0';
				if(pix[i][j]==1){
					temp.x=i;
					temp.y=j;
					vtr.push_back(temp);
					dist[i][j]=0;
				}
				else
				dist[i][j]=INT_MAX;
			}
		}
		for(int i=0;i<vtr.size();++i){
			find(n, m,vtr[i].x, vtr[i].y);
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout << dist[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
