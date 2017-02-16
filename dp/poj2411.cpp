/*************************************************************************
    > File Name: poj2411.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Feb 16 20:18:18 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;

#define LL long long

typedef pair<int,int> p;
typedef vector<p> vec;

int n,m;
vec path;
LL dp[15][1<<11];

void Dfs(int p,int i,int j)
{
	if(p>m)return;
	if(p == m){
		path.push_back(make_pair(i,j));
		return;
	}

	Dfs(p+2,4*i+3,4*j+3);
	Dfs(p+1,2*i+1,2*j);
	Dfs(p+1,2*i,2*j+1);
	return;
}


int main()
{
	freopen("input","r",stdin);
	int i,j,k;
	while(1){
		path.clear();
		cin >> n >> m;
		if((n&1) && (m&1)){
			cout << "0" << endl;
			continue;
		}
		if(!n && !m)break;
		if(n<m)swap(n,m);
		memset(dp,0,sizeof(dp));
		Dfs(0,0,0);

		dp[0][(1<<m)-1] = 1;
		for(i=1;i<=n;i++){
			for(k=0;k<path.size();k++)
				dp[i][path[k].second] += dp[i-1][path[k].first];
		}
		cout << dp[n][(1<<m)-1] << endl;
	}
	return 0;
}

