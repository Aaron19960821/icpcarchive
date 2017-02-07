#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 1005;

int mat[maxn][maxn],a[maxn][maxn][2],n;
int backtrack[maxn][maxn][2];
int dp[maxn][maxn][2],r,c;
bool iszero;

void trace(int i,int j,int mo)
{
	if(i==1 && j==1)return;

	if(backtrack[i][j][mo]){
		trace(i-1,j,mo);
		printf("D");
	}
	else{
		trace(i,j-1,mo);
		printf("R");
	}
	return;
}

int main()
{
//	freopen("input","r",stdin);
	int i,j,k;

	cin >> n;
	memset(a,0,sizeof(a));
	iszero = false;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&mat[i][j]);
			if(!mat[i][j]){
				iszero = true;
				r = i;
				c = j;
				continue;
			}
			while(!(mat[i][j]%2)){
				a[i][j][0] ++;
				mat[i][j] /= 2;
			}
			while(!(mat[i][j]%5)){
				a[i][j][1] ++;
				mat[i][j] /= 5;
			}
		}
	memset(dp,INF,sizeof(dp));
	dp[1][1][0] = a[1][1][0];
	dp[1][1][1] = a[1][1][1];

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==1&&j==1)continue;
			for(k=0;k<2;k++){
				if(dp[i-1][j][k]<dp[i][j-1][k]){
					dp[i][j][k] = dp[i-1][j][k] + a[i][j][k];
					backtrack[i][j][k] = 1;
				}
				else{
					dp[i][j][k] = dp[i][j-1][k] + a[i][j][k];
					backtrack[i][j][k] = 0;
				}
			}
		}
	}

	if(iszero && min(dp[n][n][0],dp[n][n][1])>1){
		cout << "1" << endl;
		for(i=2;i<=r;i++)printf("D");
		for(i=2;i<=n;i++)printf("R");
		for(i=r+1;i<=n;i++)printf("D");
	}
	else if(dp[n][n][0]<dp[n][n][1]){
		cout << dp[n][n][0] << endl;
		trace(n,n,0);
		cout << endl;
	}
	else{
		cout << dp[n][n][1] << endl;
		trace(n,n,1);
		cout << endl;
	}
	return 0;
}
