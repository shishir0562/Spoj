#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	while(1){
		cin >> n;
		if(n==0)
		break;
		else{
			int a[n];
			int i=0;
			while(i<n){
				cin >> a[i];
				i++;
			}
			stack<int> stk;
			i=0;
			int exp=1;
			while(i<n&&exp<=n){
				if(!stk.empty()){
					if(stk.top()==exp){
						exp++;
						stk.pop();
					}
					else
					if(a[i]==exp){
						i++;
						exp++;
					}
					else{
						stk.push(a[i]);
						i++;
					}
				}
				else{
					if(a[i]==exp){
						i++;
						exp++;
					}
					else{
						stk.push(a[i]);
						i++;
					}
				}
				
			}
			if(stk.empty()==true)
			cout << "yes\n";
			else{
				while(exp<=n&&stk.top()==exp){
					exp++;
					stk.pop();
				}
				if(stk.empty()==false)
				cout << "no\n";
				else
				cout << "yes\n";
			}
		}
	}
	return 0;
} 
