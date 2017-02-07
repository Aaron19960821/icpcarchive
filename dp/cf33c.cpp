/*************************************************************************
    > File Name: cf33c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb  7 20:42:24 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100005;

int n,arr[maxn],sum[maxn];

int main()
{
	//freopen("input","r",stdin);
	int i,j;
	int cursuf=0,maxpre=0;
	int ans = 0;
	cin >> n;

	sum[0] = 0;
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		sum[i] = sum[i-1]+arr[i];
		cursuf += arr[i];
	}
	ans = max(sum[n],-1*sum[n]);

	for(i=0;i<=n;i++){

		ans = max(ans,sum[n]-2*sum[i]);
		ans = max(ans,sum[n]-2*(sum[n]-sum[i]));

		if(sum[i]<maxpre)
			maxpre = sum[i];
		ans = max(ans,sum[n]-2*(maxpre+sum[n]-sum[i]));

	}

	cout << ans << endl;
	return 0;
}

