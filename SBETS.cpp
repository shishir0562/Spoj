#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef struct node stat;
struct node {
	int win;
	int loss;
};
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		string s1, s2;
		map<string, stat> hmap;
		int g1, g2;
		for(int i=1;i<=16;++i){
			cin >> s1;
			cin >> s2;
			cin >> g1;
			cin >> g2;
			if(g1>g2){
				hmap[s1].win++;
				hmap[s2].loss++;
			}
			else{
				hmap[s1].loss++;
				hmap[s2].win++;
			}
		}
		int maxi=0;
		string team;
		stat temp;
		for(map<string, stat>:: iterator it=hmap.begin();it!=hmap.end();++it){
			temp=it->second;
			if(temp.win>maxi){
				maxi=temp.win;
				team=it->first;
			}
		}
		cout << team << "\n";
	}
	return 0;
} 
