#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	long long int x,y,z;
	while(1){
		cin >> x >> y >> z;
		if(x==0&&y==0&&z==0)
		break;
		if(2*y==(x+z)){
			cout << "AP " << z+(z-y) << "\n"; 
		}
		else
		{
			cout << "GP "<< z*(z/y) << "\n";
		}
	}
	
	return 0;
} 
