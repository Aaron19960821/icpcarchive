/*************************************************************************
    > File Name: hdu6205.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Jan  8 22:54:45 2018
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e6+7;

int a[maxn];
int b[maxn];
int c[2*maxn];
int n;

int main()
{
	freopen("hdu6205.in","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(int i=0;i<n;i++)
		{
			c[i] = a[i] - b[i];
			c[i+n] = c[i];
		}

		int l = 0, r = 0, ans = 0;
		int curState = c[0];
		int curMax = c[0];
		while(l<n&&r<2*n)
		{
			if(curState > curMax)
			{
				ans = l;
				curMax = curState;
			}
			if(curState < 0)
			{
				curState -= c[l];
				l++;
			}
			else
			{
				r++;
				curState += c[r];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

