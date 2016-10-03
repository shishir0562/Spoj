#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    sort(a, a+n);
    int val=-1;
    int i=1;
    while(i<n){
        if(a[i-1]==a[i])
            i+=2;
        else{
            val=a[i-1];
            break;
        }
    }
    if(val==-1)
        val=a[n-1];
    printf("%d",val);
    return 0;
}
 
