/*************************************************************************
    > File Name: hdu5781.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed May  3 22:39:50 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 2005;

double dp[maxn][16];
int K,W;

void Init()
{
	int i,j,k;
	memset(dp,0,sizeof(dp));

	for(i=1;i<=2000;i++)dp[i][0] = 1e20;
	for(i=0;i<16;i++)dp[0][i] = 0.0;

	for(i=1;i<=2000;i++){
		for(j=1;j<16;j++){
			double tmp = 1e20;
			for(k=1;k<=i;k++)
				tmp = min(tmp,(dp[i-k][j]*1.0*(i-k+1.0)/(i+1))+(dp[k-1][j-1]*1.0*k/(i+1.0))+1.0);
			dp[i][j] = tmp;
		}
	}
}

int main()
{
	Init();
	while(scanf("%d%d",&K,&W)!=EOF)
		printf("%.6f\n",dp[K][min(15,W)]);
	return 0;
}

