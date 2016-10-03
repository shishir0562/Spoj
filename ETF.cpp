#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
//bool p[1000001];
/*bool isPrime(int n){
	if(n==2||n==3) return true;
	int lim=ceil(sqrt(n));
	bool flag=false;
	for(int i=2;i<=lim;i++){
		if(n%i==0){
			flag=true;
			break;
		}
	}
	if(flag) return false;
	else return true;
}*/
int main() {
	// your code goes here
	long long int t,n,sz,j,tot;
	/*vector<long long int> vtr;
	memset(p,true,sizeof(p));
	p[1]=false;
	for(long long int i=2;i<=1000;++i){     
		if(p[i]==true){
			vtr.push_back(i);
			for(long long int j=i*2;j<=100000;j+=i){
				p[j]=false;
			}
		}
	}
	sz=vtr.size();*/
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		tot=1;
		if(n==1)
		printf("%lld\n",n);
		else
		{
			tot=n;
			/*j=0;
			while(j<=n&&j<sz){
				if(n%vtr[j]==0)
				tot=tot-(tot/vtr[j]);
				j++;
			}*/
			for(long long int i=2;i*i<=n;++i){
				if(n%i==0) tot-=tot/i;
				while(n%i==0) n/=i;
			}
			if(n>1) tot-=tot/n;
			printf("%lld\n",tot);
		}
	}
	return 0;
} 
