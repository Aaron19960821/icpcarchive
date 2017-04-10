/*************************************************************************
    > File Name: spojDequery.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Apr  3 21:54:23 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

const int maxn = 30005;
const int maxq = 200005;
const int maxm = 1e6+5;

struct query{
	int l,r,id,ans;
}qlist[maxq];
int Mset[maxm];

int cnt[maxn];
int arr[maxn];
int n,q;
int ans,curl,curr;

bool comp(query a,query b)
{
	if(cnt[a.l] == cnt[b.l])return cnt[a.r]<cnt[b.r];
	else return cnt[a.l]<cnt[b.l];
}

bool comp1(query a,query b)
{
	return a.id<b.id;
}

void add(int num)
{
	if(!Mset[num])ans++;
	Mset[num]++;
}

void deleter(int num)
{
	if(Mset[num] == 1)ans--;
	Mset[num]--;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	memset(Mset,0,sizeof(Mset));

	cin >> n;
	int blocksize = sqrt(n);
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		cnt[i] = i/blocksize;
	}

	cin >> q;
	for(i=1;i<=q;i++){
		scanf("%d%d",&qlist[i].l,&qlist[i].r);
		qlist[i].id = i;
	}

	sort(qlist+1,qlist+q+1,comp);
	ans = curr = 0;
	curl = 1;
	for(i=1;i<=q;i++){
		if(curl<qlist[i].l){
			for(j=curl;j<qlist[i].l;j++)
				deleter(arr[j]);
			curl = qlist[i].l;
		}
		if(curl>qlist[i].l){
			for(j=curl-1;j>=qlist[i].l;j--)
				add(arr[j]);
			curl = qlist[i].l;
		}
		if(curr>qlist[i].r){
			for(j=curr;j>qlist[i].r;j--)
				deleter(arr[j]);
			curr = qlist[i].r;
		}
		if(curr<qlist[i].r){
			for(j=curr+1;j<=qlist[i].r;j++)
				add(arr[j]);
			curr = qlist[i].r;
		}
		qlist[i].ans = ans;
	}

	sort(qlist+1,qlist+q+1,comp1);
	for(i=1;i<=q;i++)
		printf("%d\n",qlist[i].ans);

	return 0;
}


