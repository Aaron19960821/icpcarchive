/*************************************************************************
    > File Name: kuangbin21K.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Apr 27 20:28:24 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

typedef vector<pair<int,int> >pi;

const int maxn = 15;

pi grid[maxn];
int numofchoice[maxn][1<<15];
int n,m,T;
double dp[maxn][1<<15];

void Input()
{
	int i;
	int u,v,w;

	for(i=0;i<maxn;i++)grid[i].clear();
	cin >> n >> m;

	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		grid[u].push_back(make_pair(v,w));
		grid[v].push_back(make_pair(u,w));
	}
}

void Init()
{
	int i,j,k;

	memset(numofchoice,0,sizeof(numofchoice));
	memset(dp,0,sizeof(dp));

	for(i=0;i<n;i++){
		for(j=0;j<(1<<n);j++){
			if(!(j&(1<<i)))continue;
			numofchoice[i][j]++;
			for(k=0;k<grid[i].size();k++){
				int tmp = grid[i][k].first;
				if(j&(1<<tmp))numofchoice[i][j]++;
			}
		}
	}
}

double Dfs(int cur, int state)
{
	if(dp[cur][state]>0)return dp[cur][state];
	dp[cur][state] += 5.0/ numofchoice[cur][state];
	int i;
	for(i=0;i<grid[cur].size();i++){
		int des = grid[cur][i].first;
		if(!(state & (1<<des))){
			dp[cur][state] = 1.0/ numofchoice[cur][state]*(Dfs(des,state | (1<<des))+ grid[cur][i].second);
		}
	}
	return dp[cur][state];
}

int main()
{
	freopen("input","r",stdin);
	int ncase;

	cin >> T;
	for(ncase=1;ncase<=T;ncase++){
		printf("Case %d: ",ncase);
		Input();
		Init();
		printf("%.7f\n",Dfs(0,1));
	}
	return 0;
}

