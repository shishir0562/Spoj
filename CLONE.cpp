#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
 
int main()
{
    int n, m;
    while(1){
        cin >> n >> m;
        if(n==0&&m==0) break;
        map<string, int> hmap;
        string s;
        for(int i=0;i<n;++i){
            cin >> s;
            hmap[s]++;
        }
        int a[n+1];
        memset(a, 0, sizeof(a));
        for(map<string, int>::iterator it=hmap.begin(); it!=hmap.end();++it){
            a[it->second]++;
        }
        for(int i=1;i<=n;++i) cout << a[i] << "\n";
    }
    return 0;
}
