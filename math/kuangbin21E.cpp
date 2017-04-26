/*************************************************************************
    > File Name: kuangbin21E.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Apr 17 21:23:09 2017
 ************************************************************************/

/*
 *  link: https://vjudge.net/contest/156650#problem/E
 */

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int t,n;

int solve()
{
	int i;
	double ans = 1.0;
	for(i=0;i<=n;i++){
		ans = ans*(n-i)/(n);
		if(ans<=0.50)return i;
	}
	return n;
}

int main()
{
	cin >> t;
	int ncase = 0;
	while(t--){
		cin >> n;
		printf("Case %d: %d\n",++ncase,solve());
	}
	return 0;
}

