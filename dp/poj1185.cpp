/*************************************************************************
    > File Name: poj1185.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Feb 16 18:07:42 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 105;

int av[maxn],n,m;
int c[(1<<10)+10];
int dp[105][105][105];
vector<int>legal;

int judge1(int cur)
{
	if(!(cur & (cur<<1)) && !(cur & (cur<<2)))
		return 1;
	else
		return 0;
}

int cal(int cur)
{
	int res = 0;
	while(cur){
		res ++;
		cur = cur & (cur-1);
	}
	return res;
}

int judge(int j,int k,int l)
{
	if(!(j&k) && !(j&l))
		return 1;
	else
		return 0;
}

int main()
{
	freopen("input","r",stdin);
	int i,j,k,l;
	char tmp[15];
	int maxm;

	memset(av,0,sizeof(av));
	memset(c,0,sizeof(c));
	memset(dp,0,sizeof(dp));

	cin >> n >> m;
	maxm = (1<<m);

	for(i=0;i<maxm;i++){
		if(judge1(i))legal.push_back(i);
		c[i] = cal(i);
	}


	maxm = legal.size();

	for(i=1;i<=n;i++){
		scanf("%s",tmp);
		for(j=0;j<m;j++){
			if(tmp[j] == 'H')
				av[i] |= (1<<j);
		}
	}

	for(i=0;i<maxm;i++){
		if(!(av[1] & legal[i])){
			dp[1][i][0] = c[legal[i]];
		}
	}

	for(i=2;i<=n+1;i++){
		for(j=0;j<maxm;j++){
			for(k=0;k<maxm;k++){
				for(l=0;l<maxm;l++){
					int a = legal[j],b = legal[k],d = legal[l];
					if(!(a & av[i]) && !(b & av[i-1]) && !(d & av[i-2]) && judge(a,b,d))
						dp[i][j][k] = max(dp[i][j][k],dp[i-1][k][l]+c[a]);
				}
			}
		}
	}

	int ans = 0;
	for(i=0;i<maxm;i++){
		ans = max(ans,dp[n+1][0][i]);
	}

	cout << ans << endl;


}

