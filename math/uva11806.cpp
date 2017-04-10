/*************************************************************************
    > File Name: uva11806.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Mar 18 21:22:25 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int mod = 1000007;
const int maxk = 505;
typedef long long ll;

int n,m,k,t;
ll c[maxk][maxk];


int judge(int cas)
{
	int res = 0;
	while(cas){
		res++;
		cas = cas&(cas-1);
	}
	return res;
}

ll call(int a,int b)
{
	if(b>a)return 0;
	else return c[a][b];
}

ll cal(int cas)
{
	int l = cas&1,r = cas&2, u = cas&4, d = cas&8;
	int tmp = (n-2)*(m-2);
	
	if(!l)tmp += (m-2);
	if(!r)tmp += (m-2);
	if(!u)tmp += (n-2);
	if(!d)tmp += (n-2);
	if(!l && !u)tmp++;
	if(!l && !d)tmp++;
	if(!r && !u)tmp++;
	if(!r && !d)tmp++;

	return call(tmp,k);
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	ll ans;
	cin >> t;

	memset(c,0,sizeof(c));
	c[1][1] = c[1][0] = 1;
	for(i=2;i<maxk;i++){
		c[i][0] = 1;
		for(j=1;j<=i;j++)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	}

	for(int u=1;u<=t;u++){
		printf("Case %d: ",u);
		ans = 0;
		cin >> m >> n >> k;
		if(k>m*n || k<2){
			cout << "0" << endl;
			continue;
		}

		ans = c[m*n][k]%mod;
		for(i=1;i<(1<<4);i++){
			if(judge(i)&1)ans = (ans+mod-cal(i))%mod;
			else ans = (ans+cal(i))%mod;
		}
		cout << ans << endl;
	}
	return 0;
}
