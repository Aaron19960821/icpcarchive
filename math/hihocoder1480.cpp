/*************************************************************************
    > File Name: hihocoder1480.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Mar 15 22:55:36 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int mod = 1e9+7;
const int maxn = 330003;
typedef long long ll;

int n,m;
ll fac[maxn];

ll quickpow(ll a, ll b)
{
	ll res = 1;
	while(b){
		if(b&1)res = (res*a)%mod;
		a = (a*a)%mod;
		b = b>>1;
	}
	return res;
}

int main()
{
	int i;
	ll ans = 0;
	fac[0] = fac[1] = 1;
	cin >> n >> m;
	for(i=2;i<=n*m;i++)
		fac[i] = (fac[i-1]*i)%mod;

	ans = fac[n*m];
	for(i=0;i<m;i++)
		ans = (ans*fac[i])%mod;

	for(i=n;i<m+n;i++)
		ans = (ans*quickpow(fac[i],mod-2))%mod;

	cout << ans << endl;
	return 0;
}


