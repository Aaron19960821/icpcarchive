/*************************************************************************
    > File Name: hihocoder1476.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Mar 18 20:00:35 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

typedef long long ll;

int n,m,k;
vector<pair<int,int> >p;
ll ans;

int main()
{
	//freopen("input","r",stdin);
	int i,j,tmp1,tmp2;

	cin >> n >> m >> k;
	ans = (ll)n*(n+1)/2*m*(m+1)/2;
	for(i=0;i<k;i++){
		scanf("%d%d",&tmp1,&tmp2);
		p.push_back(make_pair(tmp1,tmp2));
	}

	for(i=1;i<(1<<k);i++){
		int lr=m+10,rr=-1,uc=n+10,dc=-1;
		int bits = 0;
		for(j=0;j<k;j++){
			if(i&(1<<j)){
				lr = min(lr,p[j].first);
				rr = max(rr,p[j].first);
				uc = min(uc,p[j].second);
				dc = max(dc,p[j].second);
				bits++;
			}
		}
		ll tmp = (ll)lr*(n-rr+1)*uc*(m-dc+1);
		//cout << tmp << endl;
		if(bits&1)ans -= tmp;
		else ans += tmp;
	}

	cout << ans << endl;
	return 0;
}

