/*************************************************************************
    > File Name: sgu294.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Feb 26 15:13:15 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const int m = 10000;
int n;

struct BigInteger
{
	int bitn;
	int arr[10005];

	//init the big integer
	BigInteger(ll n){
		bitn = 0;
		memset(arr,0,sizeof(arr));
		do{
			arr[bitn++] = n%m;
			n /= m;
		}while(n);
	}

	friend BigInteger operator+(BigInteger a,BigInteger b){
		int carry = 0,i;
		BigInteger res = BigInteger(0);
		res.bitn = max(a.bitn,b.bitn);
		for(i=0;i<res.bitn;i++){
			res.arr[i] = carry + a.arr[i] + b.arr[i];
			if(res.arr[i]>=m){
				carry = res.arr[i]/m;
				res.arr[i] %= m;
			}
			else carry = 0;
		}
		if(carry)res.arr[res.bitn++] = carry;
		return res;
	}

	friend BigInteger operator*(BigInteger a,BigInteger b){
		int carry;
		BigInteger res = BigInteger(0);
		int i,j;

		for(i=0;i<=a.bitn;i++){
			for(j=0,carry=0;j<=b.bitn;j++){
				res.arr[i+j] += a.arr[i]*b.arr[j]+carry;
				carry = res.arr[i+j]/m;
				res.arr[i+j] %= m;
			}
		}

		res.bitn = a.bitn + b.bitn;
		while(!res.arr[res.bitn-1] && res.bitn>0)res.bitn--;
		return res;
	}

	friend BigInteger operator^(BigInteger a,int k){
		BigInteger res = BigInteger(1);
		int i;
		while(k){
			if(k&1)res = res*a;
			//res.output();
			a = a*a;
			k = k>>1;
		}
		return res;
	}

	friend BigInteger operator/(BigInteger a,int k){
		int i;
		int carry = 0;
		for(i=a.bitn-1;i>=0;i--){
			carry = carry*m+a.arr[i];
			a.arr[i] = carry/k;
			carry = carry%k;
		}
		while(a.bitn>0&&!a.arr[a.bitn-1])a.bitn--;
		return a;
	}

	void output(){
		int i;
		printf("%d",arr[bitn-1]);
		for(i=bitn-2;i>=0;i--)printf("%04d",arr[i]);
		printf("\n");
	}
};

int phi[2*10005],pri[2*10005];

void Linear_Shaker(){
	int tot = 0;
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!phi[i]){
			phi[i]=i-1;
			pri[++tot]=i;
		}
	for(int j=1;j<=n;j++){
		if(i*pri[j]>n)break;
		if(i%pri[j]!=0)
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		else{
			phi[i*pri[j]]=phi[i]*pri[j];
			break;
		}    
	}
	}
}

int main()
{
	int i,d;
	cin >> n;
	Linear_Shaker();
	BigInteger ans = BigInteger(0);
	for(d=1;d<=n;d++){
		if(n%d==0){
			BigInteger a = BigInteger(2ll);
			BigInteger b = BigInteger(phi[n/d]);
			ans = ans + (a^d)*b;
	//		cout << ans.bitn << endl;
		}
	}
	ans = ans/n;
	ans.output();
	return 0;
}
