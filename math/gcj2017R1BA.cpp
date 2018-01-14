/*************************************************************************
    > File Name: gcj2017R1BA.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Apr 27 21:06:45 2017
 ************************************************************************/

/*
 * link of the problem : https://code.google.com/codejam/contest/8294486/dashboard
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;


const int maxn = 1005;
const double EPS = 1e-6;
const double INF = 1e20+7;

int T;
double K[maxn],S[maxn];
double D,N;

int main()
{
	freopen("A-large-practice.in","r",stdin);
	freopen("A-small.out","w",stdout);
	int ncase;
	int i;
	double l,r,ans;
	cin >> T;
	for(ncase=1;ncase<=T;ncase++){
		printf("Case #%d: ",ncase);
		cin >> D >> N;

		ans = -1.0;
		for(i=0;i<N;i++){
			scanf("%lf%lf",&K[i],&S[i]);
			ans = max(ans,(D-K[i])/S[i]);
		}
		printf("%.8f\n",1.0*D/ans);
	}
	return 0;
}

