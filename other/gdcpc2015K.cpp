/*************************************************************************
    > File Name: gdcpc2015K.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Apr 23 23:12:01 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

const int maxn = 1e5+7;

int arr[maxn],brr[maxn];
int n,m;
int t;

pair<int,int> judge(int cur)
{
	int res = 0, res2 = 0;
	int i,j=n-1,k=n-1;
	for(i=0;i<n;i++){
		for(;j>=0;j--){
			if(arr[i]+brr[j]<cur)
				break;
		}
		for(;k>=0;k--)
			if(arr[i]+brr[k]<=cur)
				break;
		res += (n-j-1);
		res2 += (n-k-1);
	}
	return make_pair(res2,res);
}

int main()
{
	freopen("input","r",stdin);
	int i;
	int ncase = 0;
	int ans;
	cin >> t;
	while(t--){
		printf("Case #%d: ",++ncase);
		cin >> n >> m;
		for(i=0;i<n;i++)scanf("%d",&arr[i]);
		for(i=0;i<n;i++)scanf("%d",&brr[i]);

		sort(arr,arr+n);
		sort(brr,brr+n);

		if(m>n*n){
			printf("-1\n");
			continue;
		}

		int l = arr[0]+brr[0];
		int r = arr[n-1]+brr[n-1];

		while(l<=r){
			int mid = l + (r-l)/2;
			pair<int,int> tmp = judge(mid);
			if(tmp.first > m)r = mid-1;
			else if(tmp.second < m)l = mid+1;
			else{
				ans = mid;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


