/*************************************************************************
    > File Name: cf95E.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Mar  4 20:12:46 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int maxn = 100005;

int n,m;
int fa[maxn],sum[maxn];
int numof[maxn];
vector<int>S;
vector<int>T;
LL dp[maxn];

int find_fa(int cur)
{
	if(cur == fa[cur])return cur;
	return fa[cur] = find_fa(fa[cur]);
}

void connect(int a,int b)
{
	int aa = find_fa(a);
	int bb = find_fa(b);
	if(aa != bb)
		fa[bb] = aa;
	return;
}


void Init()
{
	memset(numof,0,sizeof(numof));
	T.push_back(4);
	T.push_back(7);
	int i;
	for(i=0;;i++){
		T.push_back(T[i]*10+4);
		T.push_back(T[i]*10+7);
		if(T[i]*10>=10e+6)break;
	}
	sort(T.begin(),T.end());
	return;
}

int main()
{
//	freopen("input","r",stdin);
	int i,tmp1,tmp2,j,k;
	LL ans = -1;
	Init();

	cin >> n >> m;

	for(i=1;i<=n;i++)
		fa[i] = i;

	for(i=1;i<=m;i++){
		scanf("%d%d",&tmp1,&tmp2);
		connect(tmp1,tmp2);
	}

	for(i=1;i<=n;i++)sum[find_fa(i)]++;
	for(i=1;i<=n;i++){
		if(find_fa(i) == i)
			S.push_back(sum[i]);
	}

	for(i=0;i<S.size();i++)numof[S[i]]++;
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for(i=1;i<=n;i++){
		if(!numof[i])continue;
		for(j=n;j>=i;j--){
			for(k=1;k<=numof[i];k*=2){
				int tmp = k*i;
				if(tmp>j)break;
				else if(dp[j-tmp]>=0){
					if(dp[j]<0)dp[j] = dp[j-tmp]+k;
					else dp[j] = min(dp[j-tmp]+k,dp[j]);
				}
			}
		}
	}
	
	for(i=0;T[i]<=n;i++){
		if(dp[T[i]]>=0 && ans<0)
			ans = dp[T[i]];
		else if(dp[T[i]]>=0)ans = min(ans,dp[T[i]]);
	}
	if(ans>=0)
		cout << ans-1 << endl;
	else
		cout << "-1" << endl;
	return 0;
}

