/*************************************************************************
    > File Name: hdu5783.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed May  3 23:19:37 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
using ll = long long;

const int maxn = 1e6+7;

ll arr[maxn];
int n;

int main()
{
	int i,j;

	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=n;i++)scanf("%lld",&arr[i]);
		ll tmp = 0;
		ll ans = 0;
		for(i=n;i>0;i--){
			tmp += arr[i];
			if(tmp >= 0){
				ans++;
				tmp = 0;
			}
		}
		cout << ans << endl;
	}
}

