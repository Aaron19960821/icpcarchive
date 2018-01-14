/*************************************************************************
    > File Name: hdu5241.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon May  1 10:17:17 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

struct BigInteger{
	ll arr[30000];
	int len;

	BigInteger(int init){
		len = 1;
		memset(arr,0,sizeof(arr));
		arr[0] = init;
	}

	void adjust(){
		int i;
		for(i=0;i<len;i++){
			arr[i+1] += arr[i]/10000;
			arr[i] %= 10000;
		}
		while(arr[len-1]==0 && len>=1)len--;
	}

	friend BigInteger operator*(BigInteger a,BigInteger b){
		BigInteger ans = BigInteger(0);
		ans.len = a.len + b.len;
		for(int i=0;i<a.len;i++){
			for(int j=0;j<b.len;j++){
				ans.arr[i+j] += a.arr[i]*b.arr[j];
			}
		}
		ans.adjust();
		return ans;
	}
};

BigInteger quickpow(int init,int b)
{
	BigInteger res = BigInteger(1);
	BigInteger aa  = BigInteger(init);
	while(b){
		if(b&1)res = res*aa;
		aa = aa*aa;
		b = b >> 1;
	}
	return res;
}

void print(BigInteger res)
{
	printf("%lld",res.arr[res.len-1]);
	for(int i=res.len-2;i>=0;i--)
		printf("%04lld",res.arr[i]);
	printf("\n");
	return;
}

int main()
{
	int T,n,ncase = 0;
	cin >> T;
	while(T--){
		printf("Case #%d: ",++ncase);
		cin >> n;
		BigInteger res = quickpow(32,n);
		print(res);
	}
	return 0;
}
