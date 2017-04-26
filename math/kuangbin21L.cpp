/*************************************************************************
    > File Name: kuangbin21L.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Apr 25 20:59:39 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int C[17][17];
double np[17]; //once we have i balls get into the basket
double dp[105][1705]; //we have j balls in the basket during the first i rounds.
int T,n,m,k;
double p;

void Init()
{
	int i,j;
	memset(C,0,sizeof(C));
	C[0][0] = 1;
	for(i=1;i<=16;i++){
		C[i][0] = 1;
		for(j=1;j<=i;j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	return;
}

int main()
{
	freopen("input","r",stdin);
	int i,j,t;
	int ncase = 0;
	Init();
	cin >> T;
	while(T--){
		cin >> n >> m >> k >> p;
		for(i=0;i<=n;i++)
			np[i] = C[n][i]*pow(p,i)*pow((1-p),n-i);

		memset(dp,0,sizeof(dp));
		dp[0][0] = 1.0;
		for(i=0;i<k;i++){
			for(j=0;j<=i*n;j++){
				for(t=0;t<=n;t++){
					if(j+t<=(i+1)*n)
						dp[i+1][t+j] += np[t]*dp[i][j];
				}
			}
		}

		double ans = 0.0;
		for(i=0;i<=n*k;i++)
			ans += 1.0*i*dp[k][i];
		printf("Case %d: %.7f\n",++ncase,ans);
	}
	return 0;
}

