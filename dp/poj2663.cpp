/*************************************************************************
    > File Name: poj2663.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Feb 16 21:01:27 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

typedef long long LL;
typedef vector<LL> vi;
typedef vector<vi> mat;

mat avil = mat(8,vi(8,0));
int n;

void Dfs(int p,int i,int j)
{
	if(p>3)return;
	if(p == 3){
		avil[i][j] = 1;
		return;
	}

	Dfs(p+1,i*2,j*2+1);
	Dfs(p+1,i*2+1,j*2);
	Dfs(p+2,i*4+3,j*4+3);
	return;
}

mat matmul(mat a,mat b)
{
	int i,j,k;
	mat res = mat(a.size(),vi(a.size(),0));

	for(i=0;i<res.size();i++){
		for(j=0;j<res.size();j++){
			for(k=0;k<res.size();k++)
				res[i][j] = res[i][j] + a[i][k]*b[k][j];
		}
	}
	return res;
}

mat matpow(mat a,int b)
{
	mat res = mat(a.size(),vi(a.size(),0));
	int i;

	for(i=0;i<a.size();i++)
		res[i][i] = 1;

	while(b){
		if(b&1)res = matmul(res,a);
		a = matmul(a,a);
		b = b >> 1;
	}

	return res;
}

int main()
{
	freopen("input","r",stdin);
	Dfs(0,0,0);

	while(1){
		cin >> n;
		if(n<0)break;
		else if(n&1){
			cout << "0" << endl;
			continue;
		}

		mat ans = matpow(avil,n);
		cout << ans[7][7] << endl;
	}
}

