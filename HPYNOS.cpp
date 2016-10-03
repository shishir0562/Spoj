#include <iostream>
#include <set>
using namespace std;
 
int main() {
	// your code goes here
	int n,b,m,itr=0;
	set<int> myset;
	pair<set<int>::iterator,bool> ret;
	set<int>::iterator it;
	cin >> n;
	while(1){
		b=0;
		while(n){
			m=n%10;
			b=b+m*m;
			n/=10;
		}
		itr++;
		if(b==1){
			cout << itr;
			break;
		}
		else{
			ret=myset.insert(b);
			if(ret.second==false){
				cout << -1;
				break;
			}
		}
		n=b;
	}
	return 0;
} 
