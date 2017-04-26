/*************************************************************************
    > File Name: hdu5245.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Apr 20 22:33:05 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

int t,k;
ll n,m;

//#define TEST 1

int main()
{
	freopen("input","r",stdin);
	int i,j;
	int ncase = 0;
	cin >> t;
	while(t--){
		double ans = 0.0;
		cin >> n >> m >> k;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){

				ll le = m*m*(i-1)*(i-1);
				ll up = n*n*(j-1)*(j-1);
				ll dow = n*n*(m-j)*(m-j);
				ll re = m*m*(n-i)*(n-i);
				ll le1 = (ll)(i-1)*(i-1)*(j-1)*(j-1);
				ll re1 = (ll)(n-i)*(n-i)*(j-1)*(j-1);
				ll up1 = (ll)(i-1)*(i-1)*(m-j)*(m-j);
				ll do1 = (ll)(n-i)*(n-i)*(m-j)*(m-j);

				ll anst = le-le1-re1-up1-do1+up+dow+re;
				double tmpans = 1.0*anst/(m*m*n*n);
#ifdef TEST
				cout << tmpans << endl;
				printf("%d %d %lld %lld %lld %lld\n",i,j,le,up,dow,re);
#endif
				ans += pow(tmpans,k);
			}
		}

		printf("Case #%d: %.0f\n",++ncase,round(1.0*m*n-ans));
	}
	return 0;
}

