#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		double n;
		cin >> n;
		double s=0;
		for(int i=1;i<=n;++i){
			s=s+(double)1/(i);
		}
		s=s*n;
		printf("%0.2lf\n",s);
	}
	return 0;
} 
