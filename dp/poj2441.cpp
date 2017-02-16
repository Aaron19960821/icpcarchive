/*************************************************************************
    > File Name: poj2441.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Feb 16 17:36:47 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 25;

int n,m;
int c[1<<20],a[maxn][maxn];
int dp[1<<20];

int cal(int cur)
{
	int res = 0;
	while(cur){
		res ++;
		cur = cur&(cur-1);
	}
	return res;
}

int main()
{
	freopen("input","r",stdin);
	scanf("%d%d",&n,&m);
	int maxm = (1<<m) - 1;
	int i,j,tmp,tmp2,k;
	int ans = 0;

	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));

	if(m<n){
		cout << "0" << endl;
		return 0;
	}

	for(i=0;i<=maxm;i++)
		c[i] = cal(i);

	for(i=1;i<=n;i++){
		scanf("%d",&tmp);
		for(j=1;j<=tmp;j++){
			scanf("%d",&tmp2);
			a[i][tmp2-1] = 1;
		}
	}

	dp[0] = 1;
	for(i=1;i<=n;i++){
		for(j=maxm;j>0;j--){
			if(c[j] <= i){
				for(k=0;k<m;k++){
					if(j & (1<<k)){
						dp[j] = dp[j] + dp[j-(1<<k)]*a[i][k];
					}
				}
			}
		}
	}

	for(i=maxm;i>=0;i--){
		if(c[i] == n){
			ans += dp[i];
		}
	}

	cout << ans << endl;
	return 0;
}

