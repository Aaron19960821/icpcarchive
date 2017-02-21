/*************************************************************************
    > File Name: cf77c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb 21 18:38:12 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

typedef long long LL;
const int maxn = 100005;

int k[maxn],n,s;
vector<int>grid[maxn];
LL dp[maxn];

LL Dfs(int fa,int cur)
{
	vector<LL>d;
	int i;
	LL last=0;

	for(i=0;i<grid[cur].size();i++){
		int des = grid[cur][i];
		if(des != fa){
			k[des]--;
			d.push_back(Dfs(cur,des));
			last += k[des];
		}
	}
	if(!d.size())return 0;

	sort(d.rbegin(),d.rend());

	for(i=0;i<d.size() && k[cur]>0;i++){
		dp[cur] += (d[i]+2);
		k[cur]--;
	}
	//cout << cur << " " << d.size() << endl;

	LL tm = min(last,(LL)k[cur]);
	k[cur] -= tm;
	dp[cur] += 2*tm;
	return dp[cur];
}

int main()
{
	//freopen("input","r",stdin);
	int i,tmp1,tmp2;
	cin >> n;
	for(i=1;i<=n;i++)scanf("%d",&k[i]);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&tmp1,&tmp2);
		grid[tmp1].push_back(tmp2);
		grid[tmp2].push_back(tmp1);
	}
	cin >> s;

	Dfs(-1,s);
	cout << dp[s] << endl;
	return 0;
}

