#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// your code goes here
	int g,b;
	while(1){
		cin >> g >> b;
		if(g==-1&&b==-1)
		break;
		else{
			if(g==0&&b==0)
			cout << 0 << "\n";
			else
			if(g==b||g==b-1||b==g-1)
			cout << 1 << "\n";
			else
			if(g==0&&b!=0)
			cout << b << "\n";
			else
			if(g!=0&&b==0)
			cout << g << "\n";
			else{
				if(g>b){
					cout << ceil((double)g/(b+1)) << "\n";
				}
				else{
					cout << ceil((double)b/(g+1)) << "\n";
				}
			}
		}
	}
	return 0;
} 
