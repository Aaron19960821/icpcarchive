/*************************************************************************
    > File Name: uva10325.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Mar 18 19:32:01 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

int n,m;
int arrm[16];
ll ans;

int gcd(int n,int m)
{
	if(n%m==0)return m;
	else return gcd(m,n%m);
}

int main()
{
	freopen("input","r",stdin);
	int i,j;

	while(scanf("%d%d",&n,&m)!=EOF){
		ans = 0;
		for(i=0;i<m;i++)
			scanf("%d",&arrm[i]);

		for(i=1;i<(1<<m);i++){
			ll tmp = 1;
			int bits = 0;
			for(j=0;j<m;j++){
				if(i&(1<<j)){
					tmp = (tmp*(ll)arrm[j])/(ll)gcd(tmp,arrm[j]);
					bits++;
				}
			}
			if(bits&1)ans += n/tmp;
			else ans -= n/tmp;
		}

		cout << n-ans << endl;
	}
	return 0;
}

