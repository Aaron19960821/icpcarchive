/*************************************************************************
    > File Name: cf13c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Feb 17 18:39:35 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxn = 5005;

int a[maxn],b[maxn];
int n;
LL dp[maxn];

int main()
{
//	freopen("input","r",stdin);
	int i,j;

	cin >> n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}

	memset(dp,0,sizeof(dp));
	sort(b+1,b+n+1);

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dp[j] += abs(b[j]-a[i]);
			if(j>1)dp[j] = min(dp[j],dp[j-1]);
		}
	}

	cout << dp[n] << endl;

	return 0;
}

