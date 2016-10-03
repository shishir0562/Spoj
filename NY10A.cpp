#include <iostream>
#include<map>
using namespace std;
 
int main() {
	// your code goes here
	int p;
	cin >> p;
	char scan[8][4]={"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};
	while(p--){
		int n,hashcode;
		string s;
		map<int,int> hmap;
		cin >> n;
		cin >> s;
		int l=40;
		int t=13;
		/*for(int i=0;i<8;++i){
			int hash=t*scan[i][0]+(t*t)*scan[i][1]+(t*t*t)*scan[i][2];
			cout << hash << "\n";
		}*/
		for(int i=0;i<=37;++i){
			hashcode=t*s[i]+(t*t)*s[i+1]+(t*t*t)*s[i+2];
			hmap[hashcode]++;
		}
		cout << n << " ";
		for(int i=0;i<8;++i){
			hashcode=t*scan[i][0]+(t*t)*scan[i][1]+(t*t*t)*scan[i][2];
			cout << hmap[hashcode] << " ";
		}
		cout << "\n";
	}
	return 0;
} 
