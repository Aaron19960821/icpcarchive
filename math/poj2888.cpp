/*************************************************************************
    > File Name: poj2888.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Feb 27 19:48:24 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int mod = 9973;
const int maxn = 13;

typedef long long LL;

struct Matrix
{
	int arr[maxn][maxn];
	int d;

	friend Matrix operator*(Matrix a,Matrix b){
		Matrix res;
		res.d = a.d;
		int i,j,k;
		for(i=0;i<res.d;i++){
			for(j=0;j<res.d;j++){
				res.arr[i][j] = 0;
				for(k=0;k<res.d;k++)
					res.arr[i][j] = (res.arr[i][j]+(a.arr[i][k]*b.arr[k][j]));
				res.arr[i][j] %= mod;
			}
		}
		return res;
	}

	friend Matrix operator^(Matrix a,int x){
		Matrix res;
		res.d = a.d;
		memset(res.arr,0,sizeof(res.arr));
		for(int i=0;i<res.d;i++)res.arr[i][i] = 1;
		while(x){
			if(x&1)res = res*a;
			a = a*a;
			x = x>>1;
		}
		return res;
	}
}ma;

int n,m,k,t;

int solve(int cur)
{
	int i;
	Matrix re = ma^cur;
	int ans = 0;
	for(i=0;i<ma.d;i++)
		ans = (ans+re.arr[i][i])%mod;
	//cout << ans << endl;
	return ans;
}

LL quickmod(LL a,int b)
{
	long long res = 1;
	while(b){
		if(b&1)res = (res*a)%mod;
		a = (a*a)%mod;
		b = b>>1;
	}
	return res;
}

int phi(int x)
{
   int r=x;
   for(int i=2;i*i<=x;i++){
   		if(x%i==0){r-=r/i;while(x%i==0)x/=i;}
   }
   if(x>1)r-=r/x;
   //cout << r << endl;
   return r%mod;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	LL ans;
	cin >> t;
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		
		ma.d = m;
		ans = 0;
		for(i=0;i<ma.d;i++)
			for(j=0;j<ma.d;j++)
				ma.arr[i][j] = 1;

		for(i=0;i<k;i++){
			int tmp1,tmp2;
			scanf("%d%d",&tmp1,&tmp2);
			ma.arr[tmp1-1][tmp2-1] = ma.arr[tmp2-1][tmp1-1] = 0;
		}

		for(i=1;i*i<=n;i++){
			if(n%i == 0){
				ans = (ans + phi(i)*solve(n/i))%mod;
				if(i*i != n){
					ans = (ans + phi(n/i)*solve(i))%mod;
				}
			}
		}

		ans = (ans*quickmod(n,mod-2))%mod;
		cout << ans << endl;
	}
	return 0;
}

