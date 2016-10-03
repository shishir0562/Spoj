#include <iostream>
#include <algorithm>
using namespace std;
int search(int a[], int beg, int end, int key){
	if(beg>end) return -1;
	while(beg<=end){
		int mid=(end+beg)/2;
		if(a[mid]==key) return mid;
		else
		if(a[mid]<key)
		beg=mid+1;
		else
		end=mid-1;
	}
	return -1;
}
int main() {
	// your code goes here
	int n,m;
	while(1){
		cin >> n;
		if(n==0) break;
		else{
			int max1=0,max2=0;
			int a[n];
			for(int i=0;i<n;++i) cin >> a[i];
			cin >> m;
			int b[m],j=m-1;
			for(int i=0;i<m;++i) cin >> b[i];
			for(int i=n-1;i>=0;--i){
				int index=search(b,0,m-1,a[i]);
				if(index!=-1){
					while(b[j]!=a[i]&&j>=0){
						max2+=b[j];
						j--;
					}
					max1=a[i]+max(max1,max2);
					max2=max1;
					j--;
				}
				else
				max1+=a[i];
			}
			while(j>=0){
				max2+=b[j];
				j--;
			}
			cout << max(max1,max2) << "\n";
		}
	}
	return 0;
} 
