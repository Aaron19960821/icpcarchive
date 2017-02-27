/*************************************************************************
    > File Name: cf41d.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Feb 27 17:44:06 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 105;
int dp[maxn][maxn][14];
int n,m,k;
int arr[maxn][maxn];
char motion[maxn][maxn][14];

void backtrack(int i,int j,int l)
{
//	cout << i << " " << j << endl;
//	cout << l << endl; 
	if(i==n-1){
		cout << j+1 << endl;
		return;
	}
	if(motion[i][j][l] == 'R'){
		backtrack(i+1,j-1,(l-arr[i][j]+9*(k+1))%(k+1));
		cout << "R";
	}
	else{
		backtrack(i+1,j+1,(l-arr[i][j]+9*(k+1))%(k+1));
		cout << "L";
	}
	return;
}

int main()
{
//	freopen("input","r",stdin);
	int i,j,l;
	char tmp[maxn];

	cin >> n >> m >> k;
	for(i=0;i<n;i++){
		scanf("%s",tmp);
		for(j=0;j<m;j++)
			arr[i][j] = tmp[j] - '0';
	}

	memset(dp,-1,sizeof(dp));
	for(i=0;i<m;i++)
		dp[n-1][i][arr[n-1][i]%(k+1)] = arr[n-1][i];

	for(i=n-1;i>0;i--){
		for(j=m-1;j>=0;j--){
			for(l=0;l<=k;l++){
				if(dp[i][j][l]>=0){
					if(j+1<m){
						int x = (arr[i-1][j+1]%(k+1)+l)%(k+1);
						if(dp[i-1][j+1][x]<dp[i][j][l]+arr[i-1][j+1]){
							dp[i-1][j+1][x] = dp[i][j][l] + arr[i-1][j+1];
							motion[i-1][j+1][x] = 'R';
						}
					}
					if(j-1>=0){
						int x = (arr[i-1][j-1]%(k+1)+l)%(k+1);
						if(dp[i-1][j-1][x]<dp[i][j][l]+arr[i-1][j-1]){
							dp[i-1][j-1][x] = dp[i][j][l] + arr[i-1][j-1];
							motion[i-1][j-1][x] = 'L';
						}
					}
				}
			}
		}
	}

	int ans = -1;
	for(i=0;i<m;i++){
		if(dp[0][i][0]>=0){
			if(ans==-1 || dp[0][i][0]>dp[0][ans][0])
				ans = i;
		}
	}

	if(ans<0)
		cout << "-1" << endl;
	else{
		cout << dp[0][ans][0] << endl;
		//cout << ans+1 << endl;
		backtrack(0,ans,0);
		cout << endl;
	}
	return 0;
}

