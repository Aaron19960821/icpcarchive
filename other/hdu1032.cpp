/*************************************************************************
    > File Name: hdu1032.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Dec 12 21:12:54 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 3e6+8;
typedef long long ll;
ll dp[maxn] = {0,1};
int a,b;

ll dfs(ll num)
{
	ll sol = 0;
	if(num<maxn && dp[num] != 0)
		return dp[num];

	if(num & 1)
		sol = dfs(3*num+1) + 1;
	else
		sol = dfs(num>>1) + 1;
	if(num < maxn)
		dp[num] = sol;
	return sol;
}

int main()
{
	for(int i=1;i<1000000;i++)
		dfs(i);
	while(scanf("%d%d",&a,&b))
	{
		printf("%d %d ",a,b);
		ll ans = 0;
		if(a>b)swap(a,b);
		for(int i=a;i<=b;i++)
		{
			ans = max(ans, dfs(i));
		}
		printf("%lld",ans);
	}
}

