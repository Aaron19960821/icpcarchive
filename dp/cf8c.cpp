/*************************************************************************
    > File Name: cf8c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Feb 10 19:46:44 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

#define maxn 30
#define maxc 1<<24
#define INF 0x3f3f3f3f

int dp[maxc],pre[maxc],n,d[maxn][maxn];
pair<int,int>pi[maxn];

void backtrack(int cur)
{
	int i;
	if(!cur)return;
	backtrack(cur-pre[cur]);
	for(i=0;i<n;i++){
		if(pre[cur]&(1<<i))
			printf("%d ",i+1);
	}
	printf("0 ");
	return;
}

int main()
{
	//freopen("input","r",stdin);
	int i,j,tmp1,tmp2,k;

	cin >> tmp1 >> tmp2 >> n;
	pi[n].first = tmp1; pi[n].second = tmp2;

	memset(dp,INF,sizeof(dp));

	for(i=0;i<n;i++)
		scanf("%d%d",&pi[i].first,&pi[i].second);

	for(i=0;i<=n;i++){
		for(j=i;j<=n;j++){
			d[i][j] = d[j][i] = (pi[i].first-pi[j].first)*(pi[i].first-pi[j].first) + (pi[i].second - pi[j].second)*(pi[i].second-pi[j].second);
			//cout << d[j][i];
		}
	}

	dp[0] = 0;
	int mask = 1<<n;
	for(i=0;i<mask;i++){
		if(dp[i]==INF)continue;
		for(j=0;j<n;j++){
			if(!(i&(1<<j))){
				for(k=j;k<n;k++){
					if(!(i&(1<<k))){
						int next = i + (1<<j);
						if(j!=k)next += (1<<k);
						if(dp[next]>dp[i]+d[j][n]+d[j][k]+d[k][n]){
							dp[next] = dp[i] + d[j][n] + d[j][k] + d[k][n];
							pre[next] = (1<<j);
							if(j != k)pre[next] += (1<<k);
							//cout << next << " " << dp[next] << endl;
						}
					}
				}
				break;
			}
		}
	}

	printf("%d\n0 ",dp[mask-1]);
	backtrack(mask-1);
	cout << endl;
	return 0;
}
