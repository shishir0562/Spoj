#include <iostream>
using namespace std;
typedef long long int ll;
void merge(int a[], int beg, int mid, int end, ll &pair){
	int l=mid-beg+1;
	int m=end-mid;
	int t1[l],t2[m],k;
	for(int i=0;i<l;++i){
		t1[i]=a[beg+i];
	}
	for(int i=0;i<m;++i){
		t2[i]=a[mid+1+i];
	}
	k=beg;
	int i=0,j=0;
	while(i<l&&j<m){
		if(t1[i]<t2[j]){
			a[k]=t1[i];
			k++;
			i++;
		}
		else{
			a[k]=t2[j];
			j++;
			k++;
			pair=pair+(l-i);
		}
	}
	while(i<l){
		a[k]=t1[i];
		k++;
		i++;
	}
	while(j<m){
		a[k]=t2[j];
		k++;
		j++;
	}
	//cout << pair << "\n";
}
void mergeSort(int a[], int beg, int end,ll &pair){
	if(beg<end){
		int mid=beg+(end-beg)/2;
		mergeSort(a, beg, mid, pair);
		mergeSort(a, mid+1, end, pair);
		merge(a, beg, mid, end, pair);
	}
	else return;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;++i) cin >> a[i];
		ll pair=0;
		mergeSort(a, 0, n-1,pair);
		cout << pair << "\n";
	}
	return 0;
}
 
