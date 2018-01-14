/*************************************************************************
    > File Name: hdu6201.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Sep 11 21:40:49 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

const int maxn = 1e5+7;

struct Edge
{
	int to, cost;
	Edge(int to, int cost)
	{
		this->to = to;
		this->cost = cost;
	}
};

vector<Edge>grid[maxn];
int t;
int n;
int price[maxn];
int dp[maxn][2];
int ans;

void Dfs(int cur,int fa)
{
	dp[cur][0] = price[cur];
	dp[cur][1] = price[cur];
	for(auto edge : grid[cur])
	{
		int to = edge.to;
		int cost = edge.cost;
		if(to != fa){
			Dfs(to, cur);
			dp[cur][0] = max(dp[to][0]-cost, dp[cur][0]);
			dp[cur][1] = min(dp[to][1]+cost, dp[cur][1]);
		}
	}
	ans = max(ans, dp[cur][0]-dp[cur][1]);
	return;
}

int main()
{
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n; i++){
			scanf("%d",&price[i]);
			grid[i].clear();
		}
		int from, to, cost;
		for(int i = 0; i < n-1; i++){
			scanf("%d%d%d",&from,&to,&cost);
			grid[from].push_back(Edge(to,cost));
			grid[to].push_back(Edge(from,cost));
		}
		Dfs(1,-1);
		cout << ans << endl;
	}
	return 0;
}
