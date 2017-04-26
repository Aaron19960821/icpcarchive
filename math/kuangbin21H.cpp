/*************************************************************************
    > File Name: kuangbin21H.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Apr 18 20:13:03 2017
 ************************************************************************/

/*
 * link: https://vjudge.net/contest/156650#problem/H
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1005;

double p[maxn];
int T,t,d;

inline double C(int cur)
{
	return 1.0*cur*(cur-1.0)/2;
}

double solve(int tt,int dd)
{
	if(tt&1)return 0.0;
	else return p[tt+1];
}

void Init()
{
	int i,j;
	p[0] = p[1] = 1.0;
	for(i=2;i<maxn;i++){
		p[i] = p[i-1]*1.0/(p[i-1]*i);
	}
}

int main()
{
	//freopen("input","r",stdin);
	int i,j,ncase=0;
	Init();
	cin >> T;
	while(T--){
		cin >> t >> d;
		printf("Case %d: %.7f\n",++ncase,solve(t,d));
	}
	return 0;
}

