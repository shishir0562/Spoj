#include <iostream>
#include <string.h>
using namespace std;
 
int main() {
	char s[110];
	// your code goes here
	while((scanf("%s",s))!=-1){
		int un=0, cap=0, small=0;
		int l=strlen(s);
		bool flag=true;
		for(int i=0;i<l;++i){
			if(s[i]=='_')
			un++;
			else
			if(s[i]>='A'&&s[i]<='Z')
			cap++;
			else
			if(s[i]>='a'&&s[i]<='z')
			small++;
			else{
				cout <<"Error!\n";
				flag=false;
				break;
			}
		}
		if(flag){
			if(un>0&&cap>0)
			cout << "Error!\n";
			else{
				if(un==0){
					if(cap==0)
					printf("%s\n",s);
					else
					if(s[0]>='A'&&s[0]<='Z')
					cout << "Error!\n";
					else
					{
						for(int i=0;i<l;++i){
							if(s[i]>='A'&&s[i]<='Z')
							printf("%c%c",'_',s[i]+32);
							else
							printf("%c",s[i]);
						}
						printf("\n");
					}
				}
				else
				{
					// cap=0
					if(s[0]=='_'||s[l-1]=='_'){
						cout << "Error!\n";
					}
					else
					{
						for(int i=0;i<l-1;++i){
							if(s[i]=='_'&&s[i+1]=='_'){
								cout << "Error!\n";
								flag=false;
							}
						}
						if(flag){
							for(int i=0;i<l;++i){
								if(s[i]=='_'){
									printf("%c",s[i+1]-32);
									i++;
								}
								else
								printf("%c",s[i]);
							}
							printf("\n");
						}
					}
				}
			}
		}
	}
	return 0;
} 
