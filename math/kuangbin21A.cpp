/*************************************************************************
    > File Name: kuangbin21A.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Apr 17 18:38:52 2017
 ************************************************************************/

/*
 * link: https://vjudge.net/contest/156650#problem/A
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int n,t;

int gcd(int a,int b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

int main()
{
	freopen("input","r",stdin);
	int ncase = 0;
	cin >> t;
	while(t--){
		int sum1 = 0;
		int door1 = 0, tmp;
		cin >> n;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			sum1 += abs(tmp);
			if(tmp > 0)door1++;
		}

		if(!door1)
			printf("Case %d: inf\n",++ncase);
		else{
			int tmp2 = gcd(sum1,door1);
			printf("Case %d: %d/%d\n",++ncase,sum1/tmp2,door1/tmp2);
		}
	}
	return 0;
}

