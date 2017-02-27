/*************************************************************************
    > File Name: hdu5868.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Feb 27 21:15:42 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int mod = 1000000007;
const int maxn = 5;

typedef long long LL;

struct Matrix
{
	LL arr[maxn][maxn];
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

LL solve(int cur)
{
	if(cur == 1)return 1;
	else if(cur == 2)return 3;
	else if(cur == 3)return 4;
	else if(cur == 4)return 7;
	else{
		Matrix aa;
		aa.d = 2;
		aa.arr[0][0] = aa.arr[0][1] = aa.arr[1][0] = 1;
		aa.arr[1][1] = 0;
		aa = aa^(cur-3);
		return (4*aa.arr[0][0] + 3*aa.arr[0][1])%mod;
	}
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

LL phi(int x)
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
	int i;
	LL ans = 0;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			cout << "2" << endl;
			continue;
		}
		ans = 0;
		for(i=1;i*i<=n;i++){
			if(n%i==0){
			//	cout << solve(n/i) << endl;
				ans = (ans+phi(i)*solve(n/i))%mod;
				if(i*i!=n){
					ans = (ans+phi(n/i)*solve(i))%mod;
				}
			}
		}
		//cout << ans << endl;
		ans = (ans*quickmod(n,mod-2))%mod;
		cout << ans << endl;
	}
	return 0;
}

