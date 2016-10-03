#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main() {
	// your code goes her
	char s[110];
	int l;
	while(scanf("%s",s)!=-1){
		l=strlen(s);
		int a[110];
		if(l==1&&(s[0]=='0'||s[0]=='1'))
		cout << s[0] << "\n";
		else{
			if(s[l-1]!='0')
			s[l-1]-=1;
			else
			{
				int i=l-1;
				while(i>=0&&s[i]=='0'){
					s[i]='9';
					--i;
				}
				s[i]-=1;
			}
		    int i=l-1;
			int carry=0;
			while(i>=0){
				a[i+1]=(2*(s[i]-'0')+carry)%10;
				carry=(2*(s[i]-'0')+carry)/10;
				--i;
			}
			a[i+1]=carry;
			i=0;
			if(a[i]==0)
			i++;
			while(i<=l){
				cout << a[i];
				i++;
			}
			cout << "\n";
		}
	}
	return 0;
} 
