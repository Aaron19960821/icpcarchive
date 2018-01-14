/*************************************************************************
    > File Name: hdu5242.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon May  1 22:41:29 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pi;

const int maxn = 1e5+7;

vector<pi>res;
ll ans[maxn];
int vis[maxn];
ll v[maxn];
vector<int>grid[maxn];
int fat[maxn];
int T,N,K;

void Input()
{
	int i,tmp1,tmp2;
	cin >> N >> K;
	for(i = 0;i < maxn;i++)grid[i].clear();

	for(i = 1;i <= N;i++)scanf("%lld",&v[i]);
	for(i=1;i<=N-1;i++){
		scanf("%d%d",&tmp1,&tmp2);
		grid[tmp1].push_back(tmp2);
		grid[tmp2].push_back(tmp1);
	}
	return;
}

void Dfs1(int fa,int cur,ll val)
{
	vis[cur] = 1;
	fat[cur] = fa;
	res.push_back(make_pair(val+v[cur],cur));
	ll thisv = val + v[cur];
	int i;

	for(i=0;i<grid[cur].size();i++){
		int next = grid[cur][i];
		if(next != fa)
			Dfs1(cur,next,thisv);
	}
	return;
}

ll Dfs2(int fa,int cur)
{
	if(cur <= 0 || vis[cur])return 0;
	vis[cur] = 1;
	ll anss = v[cur] + Dfs2(cur,fat[cur]);
	if(fa < 0)ans[cur] = anss;
	return anss;
}

void Solve()
{
	int i;

	res.clear();
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));

	Dfs1(-1,1,0);
	sort(res.begin(),res.end());

	memset(vis,0,sizeof(vis));
	for(i=res.size()-1;i>=0;i--){
		int cur = res[i].second;
		if(!vis[cur])Dfs2(-1,cur);
	}

	sort(ans+1,ans+1+N);
	ll ress = 0;
	for(i=N;i>=N-K+1;i--)
		ress += ans[i];
	cout << ress << endl;
}

int main()
{
	freopen("input","r",stdin);
	int ncase = 0;
	cin >> T;
	for(ncase=1;ncase<=T;ncase++){
		printf("Case #%d: ",ncase);
		Input();
		Solve();
	}
	return 0;
}

