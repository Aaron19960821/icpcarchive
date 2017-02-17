/*************************************************************************
    > File Name: hdu1565.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Feb 17 20:51:41 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 22;

vector<int>legal;
int n,arr[maxn][maxn];
int dp[2][18000];

int judge(int cur)
{
	if(!(cur&(cur<<1)))return 1;
	else return 0;
}

int main()
{
	freopen("input","r",stdin);
	int i,j,k;

	while(scanf("%d",&n)!=EOF){

		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);
		}

		int maxm = 1<<n;

		legal.clear();
		for(i=0;i<maxm;i++){
			if(judge(i))legal.push_back(i);
		}
		maxm = legal.size();


		memset(dp,0,sizeof(dp));

		for(i=0;i<n;i++){
			memset(dp[i&1],0,sizeof(dp[i&1]));
			for(j=0;j<maxm;j++){
				int sum = 0;
				for(k=0;k<n;k++){
					if(legal[j]&(1<<k))sum += arr[i][k];
				}

				for(k=0;k<maxm;k++){
					if(!(legal[k]&legal[j]))
						dp[i&1][j] =  max(dp[i&1][j],dp[(i-1)&1][k]+sum);
				}
			}
		}

		int ans = 0;
		for(i=0;i<maxm;i++)ans = max(ans,dp[(n-1)&1][i]);

		cout << ans << endl;
	}
	return 0;

}

