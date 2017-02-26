/*************************************************************************
    > File Name: poj2409.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Feb 25 20:49:28 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
int n,m;

int gcd(int a,int b)
{
	if(!b)return a;
	else return gcd(b,a%b);
}

LL quickpow(int a,int b)
{
	LL res = 1;
	while(b){
		if(b&1)res *= a;
		a = a*a;
		b = b>>1;
	}
	return res;
}

int main()
{
	LL ans;
	int i;
	while(scanf("%d%d",&m,&n)!=EOF){
		if(!n && !m)break;
		ans = 0;
		for(i=0;i<n;i++)
			ans += quickpow(m,gcd(n,i));

		if(n&1)
			ans += n*quickpow(m,(n+1)/2);
		else{
			ans += (n>>1)*quickpow(m,n/2);
			ans += (n>>1)*quickpow(m,(n+2)/2);
		}
		ans /= 2*n;
		cout << ans << endl;
	}
}

