#include <iostream>
using namespace std;
long long int sol[31], sum[31];
int main() {
	// your code goes here
	sol[0]=1;
	sum[0]=1;
	sol[2]=3;
	sum[2]=4;
	for(int i=4;i<=30;i+=2){
		sol[i]=2*sum[i-2]+sol[i-2];
		sum[i]=sum[i-2]+sol[i];
	}
	int n;
	while(1){
		cin >> n;
		if(n==-1) break;
		if(n%2==0){
			cout << sol[n] << "\n";
		}
		else cout << 0 << "\n";
	}
	return 0;
} 
