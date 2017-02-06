/*************************************************************************
    > File Name: cf82c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Feb  6 21:48:59 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 15;
const int maxm = 1005;

int a[maxn],b[maxn],c[maxn],d[maxn],l[maxn];
int n,m,c0,d0;
int dp[maxn][maxm];

int main()
{
	//freopen("input","r",stdin);
	int i,j,k;

	cin >> n >> m >> c0 >> d0;
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		l[i] = min(a[i]/b[i],n/c[i]);
	}
	d[++m] = d0;
	l[m] = n/c0;
	c[m] = c0;

	memset(dp,0,sizeof(dp));
	for(i=1;i<=m;i++){
		for(j=n;j>=0;j--){
			for(k=0;k<=l[i];k++){
				if(j-k*c[i]>=0)
					dp[i][j] = max(dp[i-1][j-k*c[i]]+k*d[i],dp[i][j]);
				else break;
			}
		}
	}

	cout << dp[m][n] << endl;
	return 0;
}

