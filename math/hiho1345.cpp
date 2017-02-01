/*************************************************************************
    > File Name: hiho1345.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Jan 18 19:25:49 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define MOD 1000000007
#define LL long long

struct mat{
	LL arr[2][2];
	mat(){
		arr[0][0] = arr[0][1] = arr[1][0] = arr[1][1] = 0;
	}


	friend mat operator*(mat a,mat b){
		mat res = mat();
		int i,j,k;
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				for(k=0;k<2;k++){
					res.arr[i][j] = (res.arr[i][j]+(a.arr[i][k]*b.arr[k][j])%MOD)%MOD;
				}
			}
		}
		return res;
	}

	friend mat operator^(mat a,LL b){
		mat res;
		res.arr[0][0] = res.arr[1][1] = 1;
		res.arr[0][1] = res.arr[1][0] = 0;
		while(b){
			if(b&1)res = res*a;
			a = a*a;
			b = b>>1;
		}
		return res;
	}
};

LL fastmod(LL a,LL b)
{
	LL res = 1;
	a = a%MOD;
	while(b){
		if(b&1)res = res*a%MOD;
		a = a*a%MOD;
		b = b>>1;
	}
	return res;
}

int main()
{
	freopen("input","r",stdin);
	LL k1,k2,x,y,ax,ay,z;

	cin >> k1 >> k2;
	cin >> x >> y >> ax >> ay;
	cin >> z;

	mat trans,tmp1,tmp2;
	trans.arr[0][0] = k1; trans.arr[0][1] = k2;
	trans.arr[1][0] = 1;  trans.arr[1][1] = 0;

	tmp1 = trans^(x-2);
	tmp2 = trans^(y-2);

	LL a1 = tmp1.arr[0][0],b1 = tmp1.arr[0][1];
	LL a2 = tmp2.arr[0][0],b2 = tmp2.arr[0][1];

	LL upper = ((ax*a2%MOD - ay*a1%MOD)+MOD)%MOD;
	LL down = ((b1*a2%MOD-b2*a1%MOD)+MOD)%MOD;

	LL A2 = upper*fastmod(down,MOD-2)%MOD;
	LL A1 = (((ax-b1*A2%MOD)+MOD)%MOD)*fastmod(a1,MOD-2)%MOD;

	tmp1 = trans^(z-2);
	LL ans = ((A1*tmp1.arr[0][0])%MOD+(A2*tmp1.arr[0][1])%MOD)%MOD;
	cout << ans << endl;
	return 0;
}

