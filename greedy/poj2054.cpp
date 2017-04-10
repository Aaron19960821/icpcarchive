/*************************************************************************
    > File Name: poj2054.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Mar 20 20:05:07 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

const int maxn = 1005;
#define TESTING

int fa[maxn];
int c[maxn],ti[maxn];
double w[maxn];
int n,r;

int getmax()
{
	int i,res;
	double maxx = -1.0;
	for(i=1;i<=n;i++){
		if(i!=r && w[i]>maxx){
			maxx = w[i];
			res = i;
		}
	}
	return res;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	int tmp1,tmp2;
	int ans;

	while(scanf("%d%d",&n,&r)!=EOF && (n+r)){
		ans = 0;

		for(i=1;i<=n;i++){
			scanf("%d",&c[i]);
			ans += c[i];
			w[i] = c[i];
			ti[i] = 1;
		}

		for(i=0;i<n-1;i++){
			scanf("%d%d",&tmp1,&tmp2);
			fa[tmp2] = tmp1;
		}

		for(i=0;i<n-1;i++){
			int pos = getmax();
			int f = fa[pos];
			w[pos] = -2.0;
			ans += ti[f]*c[pos];
			for(j=1;j<=n;j++)
				if(fa[j]==pos)
					fa[j] = f;
			c[f] += c[pos];
			ti[f] += ti[pos];
			w[f] = (double)c[f]/ti[f];
		}

		cout << ans << endl;
	}
	return 0;
}

