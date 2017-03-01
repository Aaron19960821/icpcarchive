/*************************************************************************
    > File Name: cf11d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Mar  1 16:50:03 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define clr(a,b) memset(a,b,sizeof(a))

const int maxn = 19;
typedef unsigned long long LL;

vector<int>grid[maxn];
int n,m;
LL dp[1<<maxn][maxn];

int cal(int cur)
{
	int res = 0;
	while(cur){
		res++;
		cur = cur&(cur-1);
	}
	return res;
}

void solve()
{
	int i,j,k;
	LL ans = 0;
	for(i=0;i<n;i++)dp[1<<i][i] = 1;
	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			else{
				for(k=0;k<grid[j].size();k++){
					int dest = grid[j][k];
					//cout << i << " " << cal(i) << endl;
					if((i&(-i)) > (1<< dest))continue;
					if((i&(-i)) == (1<<dest) && cal(i)>2){
						//cout << i << " " << dest << endl;
						ans += dp[i][j];
					}
					else if(!(i&(1<<dest))){
						dp[i+(1<<dest)][dest] += dp[i][j];
					}
				}
			}
		}
	}

	cout << ans/2 << endl;
	return;
}

int main()
{
//	freopen("input","r",stdin);
	int i,j,tmp1,tmp2;

	cin >> n >> m;
	for(i=0;i<m;i++){
		scanf("%d%d",&tmp1,&tmp2);
		grid[tmp1-1].push_back(tmp2-1);
		grid[tmp2-1].push_back(tmp1-1);
	}

	clr(dp,0);
	solve();
	return 0;
}

