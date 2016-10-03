#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
char a[1000];
char b[1000];
int main() {
	// your code goes here
	while((scanf("%s",a)!=-1)&&(scanf("%s",b)!=-1)){
		//printf("%s\n%s",a,b);
		int hash1[26],hash2[26];
		int i=0;
		for(i=0;i<26;++i){
			hash1[i]=0;
			hash2[i]=0;
		}
		i=0;
		while(a[i]!='\0'){
			hash1[a[i]-97]++;
			i++;
		}
		/*for(i=0;i<26;++i)
		printf("%d",hash1[i]);*/
		i=0;
		while(b[i]!='\0'){
			hash2[b[i]-97]++;
			i++;
		}
		char s[1000];
		int mini,k=0;
		for(i=0;i<26;++i){
			mini=min(hash1[i],hash2[i]);
			//printf("%d %c", mini, i+97);
			if(mini>=1){
				int j=mini;
				for(int l=0;l<j;++l){
					s[k]=i+97;
					k++;
				}
			}
		}
		s[k]='\0';
		printf("%s\n",s);
	}
	return 0;
} 
