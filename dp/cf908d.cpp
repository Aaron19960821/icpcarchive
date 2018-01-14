/*************************************************************************
    > File Name: cf908d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Jan  3 23:45:27 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef  long long ll;

const int mod = 1e9+7;
const int maxn = 1005;

ll dp[maxn][maxn];
ll a,b;
int k;

ll quickpow(ll a,ll b,ll mod)
{
	ll ans = 1;
	while(b)
	{
		if(b&1)
		{
			ans = (ans*a)%mod;
		}
		a = (a*a)%mod;
		b = b>>1;
	}
	return ans;
}

ll cal(int a,int b)
{
	if(b>=k)return b;
	else return dp[a][b];
}

int main()
{
//	freopen("cf908d.in","r",stdin);
	cin >> k >> a >> b;

	ll pa = 1ll*(a*quickpow(a+b,mod-2,mod))%mod;
	ll pb = 1ll*(b*quickpow(a+b,mod-2,mod))%mod;


	for(int i=0;i<k;i++)
	{
		dp[k][i] = (k+i+a*quickpow(b,mod-2,mod))%mod;
	}

	for(int i=k-1;i>=1;i--)
	{
		for(int j=k;j>=0;j--)
		{
			dp[i][j] = ((pa*dp[i+1][j])%mod+(pb*cal(i,i+j))%mod)%mod;
		}
	}
	cout << dp[1][0] << endl;
}

