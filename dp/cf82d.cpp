/*************************************************************************
    > File Name: cf82d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Feb  8 19:27:30 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 1005;

int dp[maxn][maxn],n;
int arr[maxn],trace[maxn][maxn];

int Dfs(int i,int j)
{
	if(dp[i][j]>=0)return dp[i][j];
	if(i>n && j>n)return 0;
	if(i<=n && j>n)return arr[i];
	dp[i][j] = 0x3f3f3f3f;
	int tmp1 = max(arr[i],arr[j]) + Dfs(j+1,j+2);
	int tmp2 = max(arr[i],arr[j+1]) + Dfs(j,j+2);
	int tmp3 = max(arr[j+1],arr[j]) + Dfs(i,j+2);
	if(tmp1<dp[i][j]){
		dp[i][j] = tmp1;
		trace[i][j] = 3;
	}
	if(tmp2<dp[i][j]){
		dp[i][j] = tmp2;
		trace[i][j] = 5;
	}
	if(tmp3<dp[i][j]){
		dp[i][j] = tmp3;
		trace[i][j] = 6;
	}
	return dp[i][j];
}

void traceroute(int i,int j)
{
	if(i>n && j>n)return;
	if(i<=n && j>n){
		cout << i << endl;
		return;
	}


	if(trace[i][j] == 3){
		printf("%d %d\n",i,j);
		traceroute(j+1,j+2);
	}
	else if(trace[i][j] == 5){
		printf("%d %d\n",i,j+1);
		traceroute(j,j+2);
	}
	else if(trace[i][j] == 6){
		printf("%d %d\n",j,j+1);
		traceroute(i,j+2);
	}
	return;
}

int main()
{
	//freopen("input","r",stdin);
	int i;

	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(i=1;i<=n;i++)scanf("%d",&arr[i]);

	cout << Dfs(1,2) << endl;
	traceroute(1,2);
	return 0;
}


