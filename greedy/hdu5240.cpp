/*************************************************************************
    > File Name: hdu5240.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Apr 20 19:29:48 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e5+7;

struct exam{
	int r,e,l;
}finalexam[maxn];

int t,n;

bool comp(exam a,exam b)
{
	return a.e < b.e;
}

int main()
{
	freopen("input","r",stdin);
	int ncase = 0;
	int i,j;
	cin >> t;
	while(t--){
		int flag = 1;
		cin >> n;
		for(i=0;i<n;i++)
			scanf("%d%d%d",&finalexam[i].r,&finalexam[i].e,&finalexam[i].l);

		sort(finalexam,finalexam+n,comp);
		int sum = 0;
		for(i=0;i<n;i++){
			sum += finalexam[i].r;
			if(sum > finalexam[i].e){
				flag = 0;
				break;
			}
			sum += finalexam[i].l;
		}

		printf("Case #%d: ",++ncase);
		if(flag)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

