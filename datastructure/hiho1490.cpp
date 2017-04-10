/*************************************************************************
    > File Name: hiho1490.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Apr  2 16:36:07 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 105;

vector<int>dep[maxn];
vector<int>leave;
int fa[maxn];
int d[maxn][maxn];
int isleave[maxn];
int n,m,k;

int main()
{
	freopen("input","r",stdin);
	memset(d,-1,sizeof(d));
	memset(isleave,0,sizeof(isleave));
	memset(fa,0,sizeof(fa));
	int i,tmp,j;

	cin >> n >> m >> k;
	for(i=1;i<=m;i++){
		scanf("%d",&tmp);
		dep[i] = vector<int>(tmp,0);
	}

	for(i=1;i<=m;i++){
		for(j=0;j<dep[i].size();j++)
			scanf("%d",&dep[i][j]);
	}

	leave = vector<int>(k,0);
	for(i=0;i<k;i++){
		scanf("%d",&leave[i]);
		isleave[leave[i]] = 1;
	}

	for(i=0;i<k;i++)
		for(j=0;j<k;j++)
			scanf("%d",&d[leave[i]][leave[j]]);

	for(i=m;i>1;i--){
		int t = 0;
		for(t;isleave[dep[i-1][t]];t++);
		fa[dep[i][0]] = dep[i-1][t];
		for(j=1;j<=n;j++)
			d[dep[i-1][t]][j] = d[j][dep[i-1][t]] = d[dep[i][0]][j]>=0?d[dep[i][0]][j]-1:-1;

		for(j=1;j<dep[i].size();j++){
			int d1 = dep[i][j-1];
			int d2 = dep[i][j];
			if(d[d1][d2]>2){
				for(t=t+1;isleave[dep[i-1][t]];t++);
				fa[d2] = dep[i-1][t];
			}
			else fa[d2] = fa[d1];

			for(int l=1;l<=n;l++)
				d[fa[d2]][l] = d[l][fa[d2]] = d[d2][l]>=0?d[d2][l]-1:-1;
		}
	}

	for(i=1;i<=n;i++)
		printf("%d%c",fa[i],i==n?'\n':' ');
	return 0;
}

