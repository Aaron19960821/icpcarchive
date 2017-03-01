/*************************************************************************
    > File Name: cf69d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb 28 20:43:54 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

const int maxn = 2*205;

int dp[maxn][maxn],x,y,n,d;
pair<int,int>p[205];

int Dfs(int x,int y)
{
	if((x-200)*(x-200)+(y-200)*(y-200)>d*d)return 1;
	if(dp[x][y]!=-1)return dp[x][y];
	for(int i=0;i<n;i++)
		if(!Dfs(x+p[i].first,y+p[i].second))
			return dp[x][y]=1;
	return dp[x][y]=0;
}

int main()
{
//	freopen("input","r",stdin);
	int i,j;
	cin >> x >> y >> n >> d;
	x += 200,y+=200;

	for(i=0;i<n;i++)
		scanf("%d%d",&p[i].first,&p[i].second);

	memset(dp,-1,sizeof(dp));
	if(Dfs(x,y))
		cout << "Anton" << endl;
	else
		cout << "Dasha" << endl;
	return 0;
}

