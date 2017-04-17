/*************************************************************************
    > File Name: kuangbin21D.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Apr 17 19:11:25 2017
 ************************************************************************/

/*
 * link: https://vjudge.net/contest/156650#problem/D
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100*100+5;

int t,n;
double p;
double dp[maxn];

int main()
{
	freopen("input","r",stdin);
	int ncase = 0;
	int i,j;
	cin >> t;
	while(t--){
		int ans=0;
		int tmp;
		double tmpp;
		cin >> p >> n;
		memset(dp,0,sizeof(dp));
		dp[0] = 1.0;
		for(i=0;i<n;i++){
			scanf("%d%lf",&tmp,&tmpp);
			tmpp = 1.0-tmpp;
			for(j=maxn-1;j>=tmp;j--){
				if(dp[j-tmp]>=(1-p))
					dp[j] = max(dp[j],dp[j-tmp]*tmpp);
			}
		}

		for(i=maxn-1;i>=0;i--){
			if(dp[i] >= (1-p)){
				ans = i;
				break;
			}
		}

		printf("Case %d: %d\n",++ncase,ans);
	}
}

