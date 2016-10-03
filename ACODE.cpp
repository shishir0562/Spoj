#include <iostream>
#include <string.h>
using namespace std;
char s[5010];
/*int fun( int n){
    int x=0,y=0;
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(s[n-1]!='0')    
    x=fun(n-1);
    if(n>1){
        int i=s[n-1]-48+(s[n-2]-48)*10;
        /*if(i==0)
            return 0;
        if((i>9&&i<=26))
            y=fun(n-2);
    }
    return x+y;
}*/
unsigned long long int fun(int n){
	unsigned long long int tab[n+1],x=0,y=0;
	tab[0]=1;
	for(int i=1;i<=n;++i){
		x=0,y=0;
		if(s[i-1]!='0')
		x=tab[i-1];
		if(i>1){
			int k=s[i-1]-48+(s[i-2]-48)*10;
			if(k>9&&k<=26)
			y=tab[i-2];
		}
		tab[i]=x+y;
	}
	return tab[n];
}
int main()
{
    while(1){
    cin >> s;
    int l=strlen(s);
    if(l==1&&s[0]=='0')
    break;
    cout << fun(l) << "\n";
    }
    return 0;
}
