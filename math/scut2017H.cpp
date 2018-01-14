/*************************************************************************
    > File Name: scut2017H.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Apr 30 13:27:51 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e5+7;
typedef long long ll;

ll arr[maxn],h[maxn];
int t,n;

int main()
{
	freopen("input","r",stdin);
	int i;
	cin >> t;
	while(t--){
		ll ans = 0;
		cin >> n;
		for(i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
			h[arr[i]] = i;
		}

		for(i=2;i<=n;i++){
			ll now = h[i];
			ll pre = h[i-1];
			if(pre > now)
				ans += (now*(pre-now)-1);
			else
				ans += ((now-pre)*(n-now+1)-1);
		}
		if(h[1]>1)ans -= (1ll*(h[1]-1)*(h[1]-2)/2);
		if(h[1]<n)ans -= (1ll*(n-h[1]-1)*(n-h[1])/2);
		cout << ans << endl;
	}
	return 0;
}

