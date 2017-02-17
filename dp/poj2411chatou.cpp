/*************************************************************************
    > File Name: poj2411chatou.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Feb 17 19:22:28 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;

LL dp[2][1<<11];

int main()
{
	freopen("input","r",stdin);
	int i,j,n,m,k;

	while(scanf("%d%d",&n,&m)){
		if(!n && !m)break;
		int now = 1, pre = 0, maxm = 1<<m;
		memset(dp,0,sizeof(dp));
		dp[now][0] = 1;
		

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				swap(now,pre);
				memset(dp[now],0,sizeof(dp[now]));

				for(k=0;k<maxm;k++){
					if(dp[pre][k]){
						dp[now][k^(1<<j)] += dp[pre][k];
						if( j && k&(1<<(j-1)) && !(k&(1<<j)) )
							dp[now][k^(1<<(j-1))] += dp[pre][k];
					}
				}
			}
		}

		cout << dp[now][0] << endl;
	}
	return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[2][1<<11];

int main()
{
	freopen("input","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m),(n||m))
	{
		int total=1<<m;
		int pre=0,now=1;
		memset(dp[now],0,sizeof(dp[now]));
		dp[now][0]=1;

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
		{
			swap(now,pre);
			memset(dp[now],0,sizeof(dp[now]));

			for(int S=0;S<total;S++) if( dp[pre][S] )
			{
				dp[now][S^(1<<j)]+=dp[pre][S];
				if( j && S&(1<<(j-1)) && !(S&(1<<j)) )
					dp[now][S^(1<<(j-1))]+=dp[pre][S];
			}
		}

		printf("%lld\n",dp[now][0]);
	}
}
*/
