/*************************************************************************
    > File Name: hdu1796.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Mar 21 22:36:34 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1030;
typedef long long ll;

int numofele[maxn];
ll lcmcase[maxn];
int n,m,arr[15];

int cal(int num)
{
	int res = 0;
	while(num){
		res++;
		num = num&(num-1);
	}
	return res;
}

ll gcd(ll a,ll b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

int main()
{
	freopen("input","r",stdin);

	int i,j;
	ll ans;

	for(i=0;i<maxn;i++)numofele[i] = cal(i);

	while(scanf("%d%d",&n,&m)!=EOF){
		ans = 0;
		int cnt = 0;
		for(i=0;i<m;i++){
			scanf("%d",&arr[cnt]);
			if(arr[cnt])cnt++;
		}

		for(i=1;i<(1<<cnt);i++){
			lcmcase[i] = 1;
			for(j=0;j<cnt;j++){
				if(i&(1<<j))lcmcase[i] = (lcmcase[i]*arr[j])/ gcd(lcmcase[i],arr[j]);
			}
			if(numofele[i]&1)ans += (n-1)/ lcmcase[i];
			else ans -= (n-1)/ lcmcase[i];
		}

		cout << ans << endl;
	}
	return 0;
}

