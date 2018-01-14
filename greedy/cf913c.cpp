/*************************************************************************
    > File Name: cf913c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Jan  9 10:31:26 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

int n;
ll L;
ll c[35];

int main()
{
	cin >> n >> L;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&c[i]);
	}

	ll ans = 0;
	for(int i=0;i<=31;i++)
	{
		if(L & (1<<i))
		{
			/*
			 * if i < j, we know that all liters below i will be covered
			 * else we can only use bottles of 2^(j-1) litters to fill up 
			 * 2^(i)
			 */
			ll needMoney = -1;
			int minIndex = -1;
			for(int j=min(n-1,i);j>=0;j--)
			{
				ll need = 1<<max(0,i-j);
				if(needMoney<0 || need*c[j] < needMoney)
				{
					needMoney = need*c[j];
					minIndex = j;
				}
			}
			ans += needMoney;
			for(int j=i+1;j<n;j++)
			{
				ans = min(ans, c[j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

