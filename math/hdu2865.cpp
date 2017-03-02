/*************************************************************************
    > File Name: hdu2865.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Mar  2 20:18:56 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int mod = 1000000007;
LL n,k;

LL quickpow(LL a,LL b)
{
	LL res = 1;
	while(b){
		if(b&1)res = (res*a)%mod;
		a = (a*a)%mod;
		b = b>>1;
	}
	return res;
}

LL solve(LL nn,LL tk)
{
	LL ans = quickpow(tk-1,nn);
	if(nn&1)
		ans = (ans+mod-(tk-1))%mod;
	else
		ans = (ans+(tk-1))%mod;
	return ans;
}

LL phi(int x)
{
	LL r=x;
   for(int i=2;i*i<=x;i++){
   		if(x%i==0){r-=r/i;while(x%i==0)x/=i;}
   }
   if(x>1)r-=r/x;
   //cout << r << endl;
   return r%mod;
}


LL polya()
{
	LL i;
	LL ans = 0;
	k--;
	for(i=1;i*i<=n;i++){
		if(n%i==0){
			ans = (ans + solve(i,k)*phi(n/i))%mod;
			if(i*i!=n)
				ans = (ans + solve(n/i,k)*phi(i))%mod;
		}
	}
	ans = (ans*quickpow(n,mod-2))%mod;
	return ans;
}

int main()
{
	freopen("input","r",stdin);
	while(scanf("%lld%lld",&n,&k)!=EOF){
		LL ans = polya();
		printf("%lld\n",(k+1)*ans%mod);
	}
	return 0;
}

