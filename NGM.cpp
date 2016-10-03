#include <iostream>
using namespace std;
int main() {
	// your code goes here
	long long int n;
	cin >> n;
	if(n%10==0)
	cout << 2;
	else{
		cout << 1 << "\n";
		cout << n%10;
	}
	return 0;
} 
