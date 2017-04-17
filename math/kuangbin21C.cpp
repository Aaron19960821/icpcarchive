/*************************************************************************
    > File Name: kuangbin21C.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Apr 17 19:32:24 2017
 ************************************************************************/

/*
 *  link: https://vjudge.net/contest/156650#problem/C
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 1e5+7;

double ans[maxn];
int t,n;

double solve(int n)
{
	if(n == 1)return 0.0;
	if(ans[n] > 0.0)return ans[n];
	int i,j;
	vector<int>div;
	for(i=1;i<=sqrt(n);i++){
		if(n % i == 0){
			div.push_back(i);
			if(i != n/i)div.push_back(n/i);
		}
	}

	int divs = div.size();
	for(i=0;i<divs;i++){
		int now = div[i];
		if(now == 1)ans[n] += 1.0/(1.0*divs-1.0);
		else if(now == n)ans[n] += 1.0/(1.0*divs-1.0);
		else ans[n] += (solve(n/now)+1.0)/(1.0*divs-1.0);
	}
	return ans[n];
}

int main()
{
	freopen("input","r",stdin);
	int ncase = 0;
	cin >> t;
	memset(ans,0,sizeof(ans));
	while(t--){
		cin >> n;
		printf("Case %d: %.7f\n",++ncase,n==1?0.0:solve(n));
	}
}

