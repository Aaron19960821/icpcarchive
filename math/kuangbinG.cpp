/*************************************************************************
    > File Name: kuangbinG.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Apr 18 06:10:33 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


int n,t;
double ans;

int main()
{
	int i,j;
	int ncase = 0;
	cin >> t;
	while(t--){
		cin >> n;
		ans = 0.0;
		for(i=n-1;i>=0;i--)
			ans += (1.0*i)/(1.0*n-1.0*i)+1.0;
		printf("Case %d: %.7f\n",++ncase,ans);
	}
	return 0;
}

