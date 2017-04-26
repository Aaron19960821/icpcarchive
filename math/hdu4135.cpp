/*************************************************************************
    > File Name: hdu4135.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Apr 20 15:21:32 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

ll A,B,N;
int t;
vector<ll>jiexi;

void Init()
{
	ll tmpN = N;
	jiexi.clear();
	for(ll i=2;i*i<=N;i++){
		if(N%i==0){
			jiexi.push_back(i);
			while(N%i==0)N/=i;
		}
	}
	if(N>1)jiexi.push_back(N);
	N = tmpN;
}

ll solve(ll cur)
{
	ll i,j;
	vector<ll>now;
	ll ans = 0;
	now.push_back(-1);
	for(i=0;i<jiexi.size();i++){
		ll tmp = now.size();
		for(j=0;j<tmp;j++){
			now.push_back((-1)*now[j]*jiexi[i]);
		}
	}
	for(i=1;i<now.size();i++)
		ans += cur/now[i];
	return ans;
}

int main()
{
	int ncase = 0;
	cin >> t;
	while(t--){
		cin >> A >> B >> N;
		Init();
		printf("Case #%d: %lld\n",++ncase,B-solve(B)-A+solve(A-1)+1);
	}
	return 0;
}

