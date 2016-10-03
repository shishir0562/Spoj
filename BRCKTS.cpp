#include <iostream>
#include <cstdio>
using namespace std;
typedef struct node Node;
struct node{
    int open;
    int close;
};
Node tree[4*30000];
void build(char s[], int a, int b, int index){
    if(a>b) return;
    if(a==b){
        if(s[a]=='('){
            tree[index].open=1;
            tree[index].close=0;
           }
           else{
               tree[index].open=0;
               tree[index].close=-1;
           }
           return;
    }
    build(s, a, (a+b)/2, 2*index);
    build(s, (a+b)/2+1, b, 2*index+1);
    if(tree[2*index].open>0&&tree[2*index+1].close<0){
        int ad=tree[2*index].open+tree[2*index+1].close;
        if(ad<=0){
            tree[index].close=tree[2*index].close+ad;
            tree[index].open=tree[2*index+1].open;
        }
        else{
            tree[index].open=ad+tree[2*index+1].open;
            tree[index].close=tree[2*index].close;
        }
    }
    else{
        tree[index].open=tree[2*index].open+tree[2*index+1].open;
        tree[index].close=tree[2*index].close+tree[2*index+1].close;
    }
}
void update(int a, int b, int i, int index){
    if(a>b||a>i||b<i) return;
    if(a==b&&a==i){
        if(tree[index].open==1){
            tree[index].open=0;
            tree[index].close=-1;
        }
        else{
            tree[index].open=1;
            tree[index].close=0;
        }
        return;
    }
    update(a, (a+b)/2, i, 2*index);
    update((a+b)/2+1, b, i, 2*index+1);
    if(tree[2*index].open>0&&tree[2*index+1].close<0){
        int ad=tree[2*index].open+tree[2*index+1].close;
        if(ad<=0){
            tree[index].close=tree[2*index].close+ad;
            tree[index].open=tree[2*index+1].open;
        }
        else{
            tree[index].open=ad+tree[2*index+1].open;
            tree[index].close=tree[2*index].close;
        }
    }
    else{
        tree[index].open=tree[2*index].open+tree[2*index+1].open;
        tree[index].close=tree[2*index].close+tree[2*index+1].close;
    }
}
bool query(){
    if(tree[1].open==0&&tree[1].close==0) return true;
    else return false;
}
int main()
{
    int t=10;
    for(int i=1;i<=t;++i){
        int n, m, k;
        scanf("%d",&n);
        char s[n+1];
        scanf("%s",s);
        build(s, 0, n-1, 1);
        scanf("%d",&m);
        printf("Test %d:\n", i);
        while(m--){
            scanf("%d",&k);
            if(k==0){
                if(query()) printf("YES\n");
                else printf("NO\n");
            }
            else{
                update(0, n-1, k-1, 1);
            }
        }
    }
    return 0;
}
