#include <iostream>
#include <set>
using namespace std;
long long  mem[500001];
int main() {
	// your code goes here
	set<long long int> myset;
	mem[0]=0;
	mem[1]=1;
	myset.insert(0);
	myset.insert(1);
	int temp;
	for(int i=2;i<=500000;++i){
		if(mem[i-1]-i>0&&myset.find(mem[i-1]-i)==myset.end()) mem[i]=mem[i-1]-i;
		else
		mem[i]=mem[i-1]+i;
		myset.insert(mem[i]);
		
	}
	int k;
	while(1){
		cin >> k;
		if(k==-1)
		break;
		else{
			cout << mem[k] << "\n";
		}
	}
	return 0;
} 
