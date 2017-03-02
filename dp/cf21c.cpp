/*************************************************************************
    > File Name: cf21c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Mar  2 18:39:48 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn = 100005;
int arr[maxn],pre[maxn],suf[maxn];
int sum,presum[maxn],sufsum[maxn];
int n;

int main()
{
//	freopen("input","r",stdin);
	int i,j;
	LL ans = 0;
	sum = 0;

	cin >> n;
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	if(sum%3>0){
		cout << "0" << endl;
		return 0;
	}
	for(i=1;i<=n;i++)pre[i] = pre[i-1]+arr[i];
	for(i=n;i>=1;i--)suf[i] = suf[i+1]+arr[i];
	for(i=n;i>=1;i--){
		if(suf[i] == sum/3)sufsum[i] = 1;
		sufsum[i] += sufsum[i+1];
	}

	for(i=1;i<n;i++){
		if(pre[i] == sum/3){
			ans += sufsum[i+1];
			if(suf[i+1] == sum/3)ans--;
		}
	}

	cout << ans << endl;
	return 0;
}

