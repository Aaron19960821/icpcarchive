/*************************************************************************
    > File Name: cf915c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Jan 14 15:59:16 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll a,b;
ll ans;
ll curAns;
int digits[11];
int bNumber[20];

int Init()
{
	ll tmp = a;
	while(tmp)
	{
		digits[tmp%10]++;
		tmp/=10;
	}
	tmp = b;
	int i = 0;
	for(i=0;tmp>0;i++,tmp/=10)
	{
		bNumber[i] = tmp%10;
	}
	return i-1;
}

void Dfs(int step, bool isNegative)
{
	if(step < 0)
	{
		ans = max(ans, curAns);
		return;
	}
	int bond = isNegative?9:bNumber[step];
	for(int i=bond;i>=0;i--)
	{
		if(digits[i]>0)
		{
			digits[i]--;
			curAns = curAns*10+i;
			Dfs(step-1, isNegative || i<bNumber[step]);
			if(ans > 0)
			{
				break;
			}
			else
			{
				digits[i]++;
				curAns = (curAns-i)/10;
			}
		}
	}
}

int main()
{
//	freopen("cf915c.in","r",stdin);
	cin >> a >> b;
	ans = curAns = 0;
	int len = Init();
	int sum = 0;

	for(int i=0;i<=9;i++)
	{
		sum+=digits[i];
	}
	if(sum<len+1)
		Dfs(sum-1,true);
	else
		Dfs(len,false);

	cout << ans << endl;
}

