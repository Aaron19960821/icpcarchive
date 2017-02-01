/*************************************************************************
    > File Name: hiho1090.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Jan 25 19:28:23 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 35
#define MAXM 20005

int A[MAXN],B[MAXN];
int dp[MAXN][MAXM],n,m;
int stepcost[MAXN][MAXM],tolcost[MAXN][MAXM];

int main()
{
	freopen("input","r",stdin);
	int i,j,k;

	memset(stepcost,0,sizeof(stepcost));
	memset(tolcost,0,sizeof(tolcost));
	memset(dp,0,sizeof(dp));

	cin >> n >> m;
	for(i=1;i<=n;i++){
		scanf("%d%d",&A[i],&B[i]);
		stepcost[i][1] = B[i];
		tolcost[i][1] = B[i];
	}

	for(i=1;i<=n;i++){
		for(j=2;;j++){
			stepcost[i][j] = 1.07*stepcost[i][j-1];
			tolcost[i][j] = tolcost[i][j-1] + stepcost[i][j];
			if(tolcost[i][j]>m)break;
		}
	}

	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			for(k=0;;k++){
				if(j-tolcost[i][k]<0)break;
				dp[i][j] = max(dp[i][j],dp[i-1][j-tolcost[i][k]]+k*A[i]);
			}
		}
	}

	cout << dp[n][m] << endl;
	return 0;
}

