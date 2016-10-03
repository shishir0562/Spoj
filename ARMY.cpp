#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		int g,m;
		cin >> g >> m;
		int a[g];
		int b[m];
		int i=0,j;
		while(i<g){
			cin >> a[i];
			i++;
		}
		i=0;
		while(i<m){
			cin >> b[i];
			i++;
		}
		sort(a,a+g);
		sort(b,b+m);
		i=0,j=0;
		while(i<g&&j<m){
			if(a[i]>=b[j])
			j++;
			else
			i++;
		}
		if(i==g)
		cout << "MechaGodzilla\n";
		else
		if(j==m)
		cout << "Godzilla\n";
	}
	return 0;
} 
