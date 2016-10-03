#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	long long int n;
	while(t--){
		int play;
		cin >> n >> play;
		if(play==0)
		cout << "Airborne wins.\n";
		else
		cout << "Pagfloyd wins.\n";
	}
	return 0;
} 
