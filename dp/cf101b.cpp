/*************************************************************************
    > File Name: cf101b.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Feb  9 21:23:17 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int mod = 1000000007;
const int maxn = 100005;
#define LL long long

LL dp[2*maxn];
int n,m,k;
vector<int>stop;
pair<int,int>bus[maxn];
map<int,int>mi;
vector<int>busl[2*maxn];
LL treearray[2*maxn];

void add(int index,int num)
{
	while(index<=k){
		treearray[index] = (treearray[index]+num)%mod;
		index += index&(-index);
	}
	return;
}

int sum(int index)
{
	int res = 0;
	while(index){
		//cout << index << " ";
		res = (res+treearray[index])%mod;
		index -= index&(-index);
	}
	//cout << endl;
	return res;
}

int main()
{
	//freopen("input","r",stdin);
	int i,j;

	memset(treearray,0,sizeof(treearray));
	memset(dp,0,sizeof(dp));
	cin >> n >> m;
	for(i=0;i<m;i++){
		scanf("%d %d",&bus[i].first,&bus[i].second);
		stop.push_back(bus[i].first);
		stop.push_back(bus[i].second);
	}
	stop.push_back(0);
	stop.push_back(n);

	sort(stop.begin(),stop.end());
	stop.erase(unique(stop.begin(),stop.end()),stop.end());

	k = stop.size();
	for(i=0;i<k;i++)mi[stop[i]] = i;
	for(i=0;i<m;i++)
		busl[mi[bus[i].second]].push_back(mi[bus[i].first]);
	add(1,1);

	for(i=1;i<k;i++){
		for(j=0;j<busl[i].size();j++){
			dp[i] = (dp[i]+sum(i)-sum(busl[i][j])+mod)%mod;
			//cout << sum(i+1) <<  " " << sum(busl[i][j]) << endl;
		}
		add(i+1,dp[i]);
	}
	cout << dp[k-1] << endl;
	return 0;
}

