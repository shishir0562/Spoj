#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	// your code goes here
	int t;
	cin >> t;
	int j=1;
	while(j<=t){
		long long int borrow, frnds;
		cin >> borrow >> frnds;
		long long int a[frnds],sum=0;
		long long int i=0;
		while(i<frnds){
			cin >> a[i];
			sum+=a[i];
			i++;
		}
		if(sum<borrow)
		cout << "Scenario #" << j << ":\n" <<"impossible\n";
		else{
			sort(a,a+frnds);
			long long int count=0;
			for(long long int i=frnds-1;i>=0;--i){
				if(borrow>0){
					borrow-=a[i];
					count++;
				}
				else break;
			}
			cout << "Scenario #" << j << ":\n" <<count << "\n";
		}
		j++;
	}
	return 0;
} 
