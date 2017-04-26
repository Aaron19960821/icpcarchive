/*************************************************************************
    > File Name: hdu5236.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Apr 21 07:36:35 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e5+7;

double p;
int n,x,t;
double E[maxn];

void solve()
{
	int i;
	memset(E,0,sizeof(E));
	for(i=1;i<=n;i++){
		E[i] = (1.0*E[i-1]+1.0)/(1.0-p);
	//	cout << E[i] << endl;
	}

	double ans = 1e20+7;
	for(i=1;i<=n;i++){
		int cnt = n%i;
		double anst = (i-cnt)*E[n/i] + E[n/i+1]*cnt + i*x;
		ans = min(ans,anst);
	}
	printf("%.6f\n",ans);
	return;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	int ncase = 0;
	cin >> t;

	while(t--){
		printf("Case #%d: ",++ncase);
		cin >> n >> p >> x;
		solve();
	}
	return 0;
}

