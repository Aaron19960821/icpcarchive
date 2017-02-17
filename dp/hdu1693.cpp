/*************************************************************************
    > File Name: hdu1693.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Feb 17 22:14:44 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;

LL dp[2][1<<12];

int main()
{
	freopen("input","r",stdin);
	int T,i,j,k;
	int n,m,v;
	int ncase=0;

	cin >> T;

	while(T--){
		cin >> n >> m;

		memset(dp,0,sizeof(dp));
		int now = 1, pre = 0, maxm = 1<<(m+1);
		dp[now][0] = 1;

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				int left = 1<<j;
				int down = 1<<(j+1);
				swap(pre,now);
				memset(dp[now],0,sizeof(dp[now]));
				scanf("%d",&v);

				for(k=0;k<maxm;k++){
					if(!v){
						if(!(k&left) && !(k&down))
							dp[now][k] += dp[pre][k];
						continue;
					}

					dp[now][k^left^down] += dp[pre][k];

					if(((k&left)!=0)^((k&down)!=0)){
						dp[now][k] += dp[pre][k];
					}
				}

			}

			swap(pre,now);
			memset(dp[now],0,sizeof(dp[now]));
			for(k=0;k<maxm/2;k++){
				dp[now][(k<<1)&(maxm-1)] += dp[pre][k];
			}
		}

		printf("Case %d: There are %lld ways to eat the trees.\n",++ncase,dp[now][0]);

	}
	return 0;
}

