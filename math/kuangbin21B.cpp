/*************************************************************************
    > File Name: kuangbin21B.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Apr 17 18:55:38 2017
 ************************************************************************/

/*
 *  link: https://vjudge.net/contest/156650#problem/B
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 105;

double ans[maxn],t,n;

int main()
{
	freopen("input","r",stdin);
	int ncase = 0;
	int i,j;
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0;i<n;i++)scanf("%lf",&ans[i]);

		for(i=n-2;i>=0;i--){
			double tmp = 0.0;
			for(j=i+1;j<n&&j<=i+6;j++){
				tmp += ans[j];
			}
			tmp /= min(6,j-i-1);
			ans[i] += tmp;
		}

		printf("Case %d: %.7f\n",++ncase,ans[0]);
	}
	return 0;
}

