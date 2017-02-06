/*************************************************************************
    > File Name: cf118d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Feb  6 20:37:58 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int mod = 100000000;
const int maxn = 105;

int n1,n2,k1,k2;
int dp[2*maxn][maxn][2][15];

int main()
{
	//freopen("input","r",stdin);
	int i,j,k;

	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp,0,sizeof(dp));
	dp[1][0][0][1] = dp[1][1][1][1] = 1;

	for(i=1;i<n1+n2;i++){
		for(j=0;j<=n1;j++){
			for(k=1;k<=k1;k++){
				dp[i+1][j][0][1] = (dp[i+1][j][0][1] + dp[i][j][1][k])%mod;
				if(k<k1)dp[i+1][j+1][1][k+1] = (dp[i+1][j+1][1][k+1] + dp[i][j][1][k])%mod;
			}

			for(k=1;k<=k2;k++){
				dp[i+1][j+1][1][1] = (dp[i+1][j+1][1][1] + dp[i][j][0][k])%mod;
				if(k<k2)dp[i+1][j][0][k+1] = (dp[i+1][j][0][k+1] + dp[i][j][0][k])%mod;
			}
		}
	}

	int ans = 0;
	for(i=1;i<=k1;i++)ans = (ans + dp[n1+n2][n1][1][i])%mod;
	for(i=1;i<=k2;i++)ans = (ans + dp[n1+n2][n1][0][i])%mod;

	cout << ans << endl;
	return 0;
}
