#include <iostream>
#include <cstdio>
using namespace std;
void swap(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}
int main() {
	// your code goes here
	int row[1234];
	int col[5678];
	for(int i=1;i<1234;++i) row[i]=i;
	for(int i=1;i<5678;++i) col[i]=i;
	char c;
	int x,y,z;
		while(cin >> c){
		//printf("%c\n",c);
		if(c=='R'){
			scanf("%d%d",&x,&y);
			swap(row[x-1],row[y-1]);
		}
		else
		if(c=='C'){
			scanf("%d%d",&x,&y);
			swap(col[x-1],col[y-1]);
		}
		else
		if(c=='Q'){
			scanf("%d%d",&x,&y);
			int val_x=row[x-1];
			int val_y=col[y-1];
			int val=val_x*5678+val_y+1;
			printf("%d\n",val);
		}
		else
		{
			scanf("%d",&z);
			int _col=(z-1)%5678;
			int _row=(z-1)/5678;
			int r,c;
			for(int i=0;i<1234;++i){
				if(row[i]==_row){
					r=i;
				}
			}
			for(int i=0;i<5678;++i){
				if(col[i]==_col){
					c=i;
				}
			}
			printf("%d %d\n",r+1,c+1);
		}
		
	}
	return 0;
} 
