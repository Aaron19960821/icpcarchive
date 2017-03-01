/*************************************************************************
    > File Name: poj2369.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb 28 21:38:12 2017
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1005;
int n,arr[N],vis[N];
vector<int>di;

int gcd(int a,int b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

int main()
{
	freopen("input","r",stdin);
	cin >> n;
	int i;
	for(i=1;i<=n;i++)scanf("%d",&arr[i]);
	memset(vis,0,sizeof(vis));

	for(i=1;i<=n;i++){
		if(!vis[i]){
			int j = arr[i];
			int d = 1;
			while(j!=i){
				d++;
				vis[j] = 1;
				j = arr[j];
			}
			di.push_back(d);
		}
	}

	int ans = 1;
	for(i=0;i<di.size();i++){
		ans = (ans*di[i])/gcd(ans,di[i]);
	}
	cout << ans << endl;
	return 0;
}

