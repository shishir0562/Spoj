#include <iostream>
#include <algorithm>
using namespace std;
int find(int a[] ,int n){
    int sum, beg, end, c=0;
    sort(a, a+n);
    for(int i=0;i<n-2;++i){
        for(int j=i+1;j<n-1;++j){
            sum=a[i]+a[j];
            beg=j+1;
            end=n-1;
            int index=-1;
            while(beg>j&&beg<=end){
                int mid=(beg+end)/2;
                if(a[mid]>sum&&a[mid-1]<=sum){
                    index=mid;
                    break;
                }
                else{
                    if(a[mid]<=sum)
                        beg=mid+1;
                    else
                        if(a[mid-1]>sum)
                        end=mid-1;
                }
 
            }
            if(index!=-1)
                c+=n-index;
        }
    }
    return c;
}
int main()
{
    int n;
    while(1){
        cin >> n;
        if(n==0)
            break;
        else{
            int a[n];
            for(int i=0;i<n;++i) cin >> a[i];
            cout << find(a, n) <<"\n";
        }
    }
    return 0;
}
 
