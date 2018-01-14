/*************************************************************************
    > File Name: scut2017I.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Apr 30 09:13:21 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

const int maxn = 1e5+7;

#define b first
#define c second
typedef long long ll;

pair<int,int>villageList[maxn];
int n,m,t;
int arr[maxn];
int choosed[maxn];
priority_queue<int,vector<int>,less<int> >Q;

bool comp(pair<int,int>a,pair<int,int>b)
{
	return (a.c-a.b) < (b.c-b.b);
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	cin >> t;
	while(t--){
		memset(choosed,0,sizeof(choosed));
		ll res = 0;
		cin >> n >> m;

		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		for(i=0;i<m;i++)
			scanf("%d%d",&villageList[i].b,&villageList[i].c);

		sort(villageList,villageList+m);
		sort(arr,arr+n);

		int ans = 0;
		i = n-1; j = m-1;
		while(i>=0 && j>=0){
			if(arr[i] <= villageList[j].b)j--;
			else{
				choosed[j] = 1;
				i--;
				j--;
				ans++;
			}
		}

		while(!Q.empty())Q.pop();

		for(i=0;i<m;i++){
			Q.push(villageList[i].c-villageList[i].b);
			if(choosed[i]){
				res += Q.top();
				Q.pop();
			}
		}

		for(i=0;i<ans;i++)
			res += arr[n-i-1];
		cout << res << endl;
	}
	return 0;
}



