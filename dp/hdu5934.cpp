/*************************************************************************
    > File Name: hdu5934.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Feb  5 15:10:00 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

#define pi pair<int,int>
#define LL long long
#define maxn 100005

struct Edge{
	int to,next,l;
}EdgeTable[2*maxn];

int head[maxn],dp[maxn][5];
int v[maxn],id[maxn];
int t,n,e;

void addedge(int from,int to,int l)
{
	EdgeTable[e].to = to;
	EdgeTable[e].l = l;
	EdgeTable[e].next = head[from];
	head[from] = e++;
}

void Dfs2(int fa,int cur,int sum1,int sum2)
{
	dp[cur][1] += sum1;
	dp[cur][2] += sum1;

	if(dp[cur][0]+sum2>dp[cur][1]){
		id[cur] = fa;
		dp[cur][2] = dp[cur][1];
		dp[cur][1] = dp[cur][0] + sum2;
	}
	else if(dp[cur][0]+sum2>dp[cur][2])
		dp[cur][2] = dp[cur][0]+sum2;
	dp[cur][0] += sum1;
	int i;

	for(i=head[cur];i!=-1;i=EdgeTable[i].next){
		int des = EdgeTable[i].to;
		if(des != fa){
			if(des != id[cur]){
				int tmp1 = max(0,dp[des][0]-2*EdgeTable[i].l);
				Dfs2(cur,des,max(0,dp[cur][0]-tmp1-2*EdgeTable[i].l),max(0,dp[cur][1]-tmp1-EdgeTable[i].l));
			} 
			else{
				int tmp1 = max(0,dp[des][0]-2*EdgeTable[i].l);
				Dfs2(cur,des,max(0,dp[cur][0]-tmp1-2*EdgeTable[i].l),max(0,dp[cur][2]-tmp1-EdgeTable[i].l));
			}
		}
	}
	return;
}

void Dfs1(int fa,int cur)
{
	int i;

	dp[cur][0] = v[cur];
	dp[cur][1] = v[cur];
	dp[cur][2] = v[cur];

	for(i=head[cur];i!=-1;i=EdgeTable[i].next){
		int des = EdgeTable[i].to;
		if(des != fa){
			Dfs1(cur,des);
			dp[cur][1] = max(dp[cur][1],dp[cur][1]+dp[des][0]-EdgeTable[i].l*2);
			dp[cur][2] = max(dp[cur][2],dp[cur][2]+dp[des][0]-EdgeTable[i].l*2);

			int tm = dp[cur][0] + dp[des][1] - EdgeTable[i].l;
			if(tm>dp[cur][1]){
				dp[cur][2] = dp[cur][1];
				dp[cur][1] = tm;
				id[cur] = des;
			}
			else if(tm>dp[cur][2])
				dp[cur][2] = tm;
			dp[cur][0] = max(dp[cur][0],dp[cur][0]+dp[des][0]-EdgeTable[i].l*2);
		}
	}

	return;
}

int main()
{
	freopen("input","r",stdin);
	int i;
	int tmp1,tmp2,tmp3,ncase=1;
	cin >> t;

	while(t--){
		cin >> n;
		for(i=1;i<=n;i++)scanf("%d",&v[i]);
		e = 0;
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));

		for(i=1;i<=n-1;i++){
			scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
			addedge(tmp1,tmp2,tmp3);
			addedge(tmp2,tmp1,tmp3);
		}

		Dfs1(-1,1);
		Dfs2(-1,1,0,0);
		printf("Case #%d:\n",ncase++);
		for(i=1;i<=n;i++)
			printf("%d\n",dp[i][1]);
	}
	return 0;
}
