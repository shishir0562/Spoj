#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
typedef struct node{
    int level;
    int n;
}Node;
bool prime[10005];
bool visited[10005];
int b[5];
void prime_table(){
    memset(prime, false, sizeof(prime));
    bool flag;
    for(int i=1000;i<=10000;++i){
        flag=true;
        for(int j=2;j<=i/2;++j){
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag)
            prime[i]=true;
    }
}
void num(int n){
    int i=1;
    while(n>0&&i<=4){
        b[i]=n%10;
        n/=10;
        i++;
    }
}
int bfs(int n1, int n2){
    if(n1==n2)
        return 0;
    queue<Node> q;
    Node temp, u;
    temp.level=0;
    temp.n=n1;
    visited[n1]=true;
    q.push(temp);
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=1;i<=4;++i){
            num(u.n);
            int c=u.n-b[i]*pow(10,i-1);
            for(int j=0;j<=9;++j){
                int v=c+j*pow(10,i-1);
                if(v>=1000&&visited[v]==false&&prime[v]==true){
                    if(v==n2)
                        return u.level+1;
                    visited[v]=true;
                    temp.n=v;
                    temp.level=u.level+1;
                    q.push(temp);
                }
            }
        }
    }
}
int main()
{
 
    int n;
    cin >> n;
    prime_table();
    while(n--){
        int n1, n2;
        memset(visited, false, sizeof(visited));
        cin >> n1 >> n2;
        cout << bfs(n1, n2) << "\n";
    }
    return 0;
}
 
