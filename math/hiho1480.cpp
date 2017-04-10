/*************************************************************************
    > File Name: hiho1480.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Mar 12 22:30:29 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const int maxn = 330005;
const int mod = 1e9+7;

int n,m;
ll fact[maxn];

ll quickpow(ll a,int b)
{
	ll res = 1;
	while(b){
		if(b&1)res = (res*a)%mod;
		b = b>>1;
		a = (a*a)%mod;
	}
	return res;
}

int main()
{
	int i,j;
	ll ans = 0;

	cin >> n >> m;
	fact[0] = fact[1] = 1;

	if(n == 1){
		cout << "1" << endl;
		return 0;
	}
	for(i=2;i<=n*m;i++)
		fact[i] = (fact[i-1]*i)%mod;
	ans = fact[n*m];
	for(i=0;i<n;i++)ans = (ans*quickpow(fact[m],mod-2))%mod;
	//for(i=0;i<m;i++)ans = (ans*quickpow(fact[n],mod-2))%mod;
	cout << ans << endl;
	return 0;
}

