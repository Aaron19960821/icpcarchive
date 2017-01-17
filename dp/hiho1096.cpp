/*************************************************************************
    > File Name: hiho1093.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Jan 17 20:42:46 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000007
#define LL long long

LL dp[105][105][55];
int m,n;

int main()
{
	int i,j,k;

	memset(dp,0,sizeof(dp));

	cin >> n >> m;
	dp[0][0][1] = 1;

	for(i=0;i<=n-1;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<m;k++){
				dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k])%MOD;
				if(j+i+1<=n){
					dp[i+1][j+i+1][(k*(i+1))%m] = (dp[i][j][k]+dp[i+1][j+i+1][(k*(i+1))%m])%MOD;
				}
			}
		}
	}

	cout << dp[n][n][0] << endl;
}

