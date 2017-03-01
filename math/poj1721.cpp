/*************************************************************************
    > File Name: poj1721.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Mar  1 21:30:55 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1005;

int n,m;
int arr[maxn],arra[maxn],arrb[maxn];

void getnext()
{
	int i;
	for(i=1;i<=n;i++)arrb[i] = arra[arra[i]];
	for(i=1;i<=n;i++)arra[i] = arrb[i];
	return;
}

bool isSame()
{
	int i;
	for(i=1;i<=n;i++)
		if(arra[i] != arr[i])return false;
	return true;
}

int main()
{
	freopen("input","r",stdin);
	cin >> n >> m;
	int i,j,s=0;

	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);

	memcpy(arra,arr,sizeof(arr));
	memcpy(arrb,arr,sizeof(arr));

	for(;;){
		getnext();
		s++;
		if(isSame())break;
	}

	m = s - m%s;
	for(i=0;i<m;i++)
		getnext();
	for(i=1;i<=n;i++)
		printf("%d\n",arra[i]);
	return 0;
}

