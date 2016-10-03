#include <iostream>
#include <cstring>
using namespace std;
int mem[13][99];
int count(int n, int k){
	if(n==0&&k!=0){
		mem[n][k]=0;
		return 0;
	}
	if(k==0){
		mem[n][k]=1;
		return 1;
	}
	int c=0;
	for(int i=0;i<n&&k-i>=0;++i){
		if(mem[n-1][k-i]!=-1)
		c+=mem[n-1][k-i];
		else{
			int temp=count(n-1,k-i);
			c+=temp;
		}
		mem[n][k]=c;
	}
	return mem[n][k];
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		memset(mem, -1, sizeof(mem));
		cout << count(n,k) << "\n";
	}
	return 0;
} 
