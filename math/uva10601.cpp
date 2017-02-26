/*************************************************************************
    > File Name: uva10601.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Feb 26 14:33:08 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

#define T dp[j][k][l][m][n][o]

int a[10];
int t;
ll dp[13][7][5][4][4][4];
ll ans = 0;
int size[13],cnt;

void backtrack()
{
	int i,j,k,l,m,n,o;
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0][0][0] = 1;
	for(i=1;i<=cnt;i++){
		for(j=a[1];j>=0;j--){
			for(k=a[2];k>=0;k--){
				for(l=a[3];l>=0;l--){
					for(m=a[4];m>=0;m--){
						for(n=a[5];n>=0;n--){
							for(o=a[6];o>=0;o--){
								if(j-size[i]>=0)T += dp[j-size[i]][k][l][m][n][o];
								if(k-size[i]>=0)T += dp[j][k-size[i]][l][m][n][o];
								if(l-size[i]>=0)T += dp[j][k][l-size[i]][m][n][o];
								if(m-size[i]>=0)T += dp[j][k][l][m-size[i]][n][o];
								if(n-size[i]>=0)T += dp[j][k][l][m][n-size[i]][o];
								if(o-size[i]>=0)T += dp[j][k][l][m][n][o-size[i]];
							}
						}
					}
				}
			}
		}
	}
}

void solve()
{
	int i;
	ans = 0;

	memset(size,0,sizeof(size));
	for(i=1;i<=12;i++)size[i] = 1;
	cnt = 12;
	backtrack();
	ans += dp[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];

	memset(size,0,sizeof(size));
	size[1] = size[2] = 1;
	for(i=3;i<=7;i++)size[i] = 2;
	cnt = 7;
	backtrack();
	ans += 6*dp[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];

	memset(size,0,sizeof(size));
	size[1] = size[2] = size[3] = 4;
	cnt = 3;
	backtrack();
	ans += 6*dp[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];

	memset(size,0,sizeof(size));
	for(i=1;i<=6;i++)size[i] = 2;
	cnt = 6;
	backtrack();
	ans += 3*dp[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];

	memset(size,0,sizeof(size));
	for(i=1;i<=4;i++)size[i] = 3;
	cnt = 4;
	backtrack();
	ans += 8*dp[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];

	cout << ans/24 << endl;
	return;
}

bool cmp(int a,int b){
	return a>b;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	cin >> t;

	while(t--){
		memset(a,0,sizeof(a));
		for(i=0;i<12;i++){
			scanf("%d",&j);
			a[j] ++;
		}
		sort(a+1,a+7,cmp);
		solve();
	}
	return 0;
}

