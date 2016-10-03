#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		int ver[m-1],hor[n-1];
		for(int i=0;i<m-1;++i)
		cin >> ver[i];
		for(int i=0;i<n-1;++i)
		cin >> hor[i];
		sort(ver, ver+m-1);
		sort(hor,hor+n-1);
		/*for(int i=0;i<m-1;++i)
		cout << ver[i];
		cout << "\n";
		for(int i=0;i<n-1;++i)
		cout <<  hor[i];*/
		int h=1,v=1;
		int i=m-2,j=n-2;
		long long int ans=0;
		while(i>=0&&j>=0){
			if(ver[i]>=hor[j]){
				ans=ans+(v*ver[i]);
				i--;
				h++;
			}
			else{
				ans=ans+(h*hor[j]);
				j--;
				v++;
			}
		}
		while(i>=0){
			ans=ans+(v*ver[i]);
			--i;
		}
		while(j>=0){
			ans=ans+(h*hor[j]);
			--j;
		}
		cout << ans << "\n";
	}
	return 0;
} 
