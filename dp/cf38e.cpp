/*************************************************************************
    > File Name: cf38.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Feb  8 21:32:48 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

#define LL long long
#define MAXN 3005
struct rock{
	LL x,c;
	int id;
}p[MAXN];

int n;
LL dp[MAXN][MAXN];
const LL INF = -1000000000000;

bool comp(rock a,rock b)
{
	if(a.x == b.x)return a.c < b.c;
	return a.x < b.x;
}

LL Dfs(int i,int j)
{
	if(i>n)return 0;
	if(dp[i][j] != -INF)return dp[i][j];
	dp[i][j] = Dfs(i+1,i)+p[i].c;
	dp[i][j] = min(dp[i][j],Dfs(i+1,j)+p[i].x-p[j].x);
	return dp[i][j];
}

int main()
{
	//freopen("input","r",stdin);
	int i,j;

	cin >> n;
	for(i=1;i<=n;i++)scanf("%lld %lld",&p[i].x,&p[i].c);
	sort(p+1,p+n+1,comp);
	p[0].x = INF;

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)
			dp[i][j] = -INF;
	}

	cout << Dfs(1,0) << endl;
	return 0;
}
