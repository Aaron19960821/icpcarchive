/*************************************************************************
    > File Name: cf54c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Feb 25 18:00:25 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
const int maxn = 1005;
const double eps = 10e-10;

int n,k;
LL l,r;
LL m[20];
double dp[maxn][maxn];
double p[maxn];

LL solve(LL cur)
{
	if(!cur)return 0;
	LL tmp = cur;
	LL ans = 0;
	int c[20],i,j;
	for(i=1;tmp;i++){
		c[i] = tmp%10;
		tmp /= 10;
	}
	i--;
	//cout << i << endl;

	if(c[i]>1)
		return m[i];
	else if(c[i] == 1){
		LL t = 1;
		for(j=1;j<i;j++){
			ans += t*c[j];
			t *= 10;
		}
		//cout << ans << endl;
		return m[i-1]+ans+1;
	}
	else return c[i-1];
}

int main()
{
//	freopen("input","r",stdin);
	cin >> n;
	int i,j;
	double ans = 0;

	LL tmp = 1;
	m[0] = 0;
	for(i=1;i<20;i++){
		m[i] = m[i-1] + tmp;
		tmp *= 10;
	}

	for(i=1;i<=n;i++){
		cin >> l >> r;
		p[i] = (double)(solve(r)-solve(l-1))/(double)(r-l+1);
		//cout << solve(l-1) << endl;
	}

	cin >> k;

	dp[0][0] = 1.0;
	for(i=1;i<=n;i++){
		dp[i][0] = dp[i-1][0]*(1-p[i]);
		for(j=1;j<=i;j++)
			dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
	}

	for(i=n;i>=0;i--){
		if((double)i/(double)n - (double)k/100.0 < -eps)break;
		else ans += dp[n][i];
	}

	printf("%.10f\n",ans);
	return 0;
}

