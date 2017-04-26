/*************************************************************************
    > File Name: hiho1015.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Apr 20 11:16:09 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxm = 1e4+5;
const int maxn = 1e6+5;

char pattern[maxm],origin[maxn];
int _next[maxm];

void get_next()
{
	_next[0] = _next[1] = 0;
	int i = 2, t = 1;
	int l = strlen(pattern+1);
	while(i <= l){
		while(t > 0 && pattern[t] != pattern[i])
			t = _next[t];
		t++;
		i++;
		if(pattern[i] == pattern[t])
			_next[i-1] = _next[t - 1];
		else _next[i-1] = t-1;
	}
}

void solve()
{
	int i,j;
	int ans = 0;
	int l = strlen(origin+1);
	int l1 = strlen(pattern+1);
	int t = 0;

	get_next();
	for(i=1;i<=l;i++){
		while(t > 0 &&origin[i]!=pattern[t+1])
			t = _next[t];

		if(origin[i] == pattern[t+1])t++;
		if(t == l1){
			ans ++;
			t = _next[t];
		}

	}
	cout << ans << endl;
	return;
}

int main()
{
//	freopen("input","r",stdin);
	int t;
	cin >> t;
	while(t--){
		scanf("%s",pattern+1);
		scanf("%s",origin+1);
		solve();
	}
	return 0;
}

