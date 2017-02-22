/*************************************************************************
    > File Name: prod.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Feb 22 18:02:36 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

typedef long long LL;

const int maxm = 250005;
const int maxl = 5005;
const int maxn = 55;

int maxss[maxn],maxst[maxn],sum[maxn],maxs[maxn];
int n,m,l[maxn],r[maxm];

int main()
{
//	freopen("input","r",stdin);
	int i,j;
	int arr[maxl],tmp1=0,tmp2=0;
	LL ans = -(5000*1000+10),tmp = 0;

	cin >> n >> m;
	for(i=1;i<=n;i++){
		scanf("%d",&l[i]);
		maxss[i] = -1005;
		maxst[i] = -1005;
		maxs[i] = -1005;
		tmp1 = tmp2 = 0;

		for(j=1;j<=l[i];j++)
			scanf("%d",&arr[j]);

		for(j=1;j<=l[i];j++){
			sum[i] += arr[j];
			tmp2 += arr[l[i]-j+1];
			tmp1 += arr[j];
			maxs[i] = max(tmp1,maxs[i]);
			maxst[i] = max(tmp2,maxst[i]);
			maxss[i] = max(maxss[i],sum[i]);
			if(tmp1<0)tmp1=0;
		}
	}

	for(i=1;i<=m;i++)
		scanf("%d",&r[i]);

	for(i=1;i<=m;i++){
		ans = max(tmp+maxss[r[i]],ans);
		tmp = max(tmp+sum[r[i]],(LL)maxst[r[i]]);
		ans = max(ans,tmp);
		ans = max(ans,(LL)maxs[r[i]]);
		tmp = max(0ll,tmp);
	}

	cout << ans << endl;
	return 0;
}

