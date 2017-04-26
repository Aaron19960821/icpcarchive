/*************************************************************************
    > File Name: kuangbin21I.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Apr 18 20:56:06 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 5005;

double dp[2][maxn][2];
int n,s;
int T;
int ncase = 0;

void Solve(int nn,int ss)
{
	int numoft = ss - 2*nn;
	int numoff = 3*nn - ss;
	int i,j;

	memset(dp,0,sizeof(dp));
	dp[1][1][0] = 1.0;
	for(i=1;i<n;i++){
		{}
		for(j=max(0,i-numoft);j<=min(i,numoff);j++){
			double pf = (1.0*numoff - j)/(1.0*n-i+1);
			double pt = 1.0-pf;
			if(j>0 && j!=i){
				dp[(i+1)&1][j+1][0] = pf*(dp[i&1][j][0]+dp[i&1][j][1]+1.0);
				dp[(i+1)&1][j][1] = pt*(dp[i&1][j][0]+dp[i&1][j][1]+1.0);
			}
			else if(!j){
				dp[(i+1)&1][j+1][0] = pf*(dp[i&1][j][1]+1.0);
				dp[(i+1)&1][j][1] = pt*dp[i&1][j][1];
			}
			else{
				dp[(i+1)&1][j+1][0] = pf*(dp[i&1][j][0]);
				dp[(i+1)&1][j][1] = pt*(dp[i&1][j][0]+1.0);
			}
		}
	}

	cout << dp[n&1][numoff][0] + dp[n&1][numoff][1] << endl;
	return;
}

int main()
{
	int i,j;

	cin >> T;
	while(T--){
		cin >> n >> s;
		Solve(n,s);
	}
	return 0;
}

