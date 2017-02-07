/*************************************************************************
    > File Name: cf4d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb  7 20:14:42 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 5005;

int h[maxn],w[maxn],to[maxn],dp[maxn],n;

int Dfs(int cur)
{
	int i;
	if(dp[cur])return dp[cur];
	dp[cur] = 1;
	for(i=1;i<=n;i++){
		if(h[cur]<h[i] && w[cur]<w[i]){
			int tmp = Dfs(i);
			if(tmp+1>dp[cur]){
				dp[cur] = tmp+1;
				to[cur] = i;
			}
		}
	}
	return dp[cur];
}

int main()
{
	//freopen("input","r",stdin);
	int i,j;
	memset(dp,0,sizeof(dp));
	memset(to,-1,sizeof(to));
	cin >> n;
	for(i=0;i<=n;i++)scanf("%d%d",&h[i],&w[i]);
	Dfs(0);
	cout << dp[0]-1 << endl;
	for(i=0;i>=0;i=to[i]){
		if(!i)continue;
		printf("%d ",i);
	}
	printf("\n");
	return 0;
}

