#include <iostream>
#include <string>
using namespace std;
int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int mod(string b, int a){
	int m=0,l=b.size(),i=0;
	while(i<l){
		m=m*10+(b[i]-48);
		m=m%a;
		i++;
	}
	return m;
}
int main() {
	int t,a;
	string b;
	cin >> t;
	while(t--){
		cin >> a;
		cin >> b;
		if(a==0)
		cout << b << "\n";
		else
		{
			int m=mod(b,a);
			if(m==0)
			cout << a << "\n";
			else
			cout << gcd(a,m) << "\n";
		}
	}
	return 0;
} 
