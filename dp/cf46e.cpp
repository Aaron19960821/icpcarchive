/*************************************************************************
    > File Name: cf46e.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Feb 19 18:53:11 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int maxn = 1505;
LL mat[maxn][maxn],dp[2][maxn];
int n,m;
const long long inf = 10e13;

int main()
{
//	freopen("input","r",stdin);
	int i,j;

	memset(dp,0,sizeof(dp));

	cin >> n >> m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%I64d",&mat[i][j]);
			mat[i][j] += mat[i][j-1];
		}

	for(i=1;i<=m;i++)dp[1][i] = mat[1][i];

	for(i=2;i<=n;i++){
		if(i&1){
			dp[i&1][1] = -inf;
			for(j=2;j<=m;j++){
				dp[i&1][j] = dp[(i-1)&1][j-1] + mat[i][j];
				dp[i&1][j] = max(dp[i&1][j],dp[i&1][j-1]-mat[i][j-1]+mat[i][j]);
			}
		}
		else{
			dp[i&1][m] = -inf;
			for(j=m-1;j>=1;j--){
				dp[i&1][j] = dp[(i-1)&1][j+1] + mat[i][j];
				dp[i&1][j] = max(dp[i&1][j],dp[i&1][j+1]-mat[i][j+1]+mat[i][j]);
			}
		}
	}

	LL ans = -inf;
	for(i=1;i<=m;i++)ans = max(ans,dp[n&1][i]);
	cout << ans << endl;
	return 0;
}

