/*************************************************************************
    > File Name: hiho1356.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Jan 17 15:54:22 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<set>
#include<utility>
#include<queue>
using namespace std;

#define pi pair<int,int>

map<int,int>cnt;
set<pi>S;
int n;

int main()
{
	freopen("input","r",stdin);
	int i,j;
	int last = -1,cur;
	map<int,int>::iterator it;

	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&j);
		cnt[j]++;
	}

	for(it=cnt.begin();it!=cnt.end();it++)
		S.insert(make_pair(it->second,it->first));

	if((--S.end())->first*2-1>n){
		cout << "-1" << endl;
		return 0;
	}

	for(i=1;i<=n;i++){
		if((--S.end())->first*2-1==n-i+1)
			cur = (--S.end())->second;
		else{
			it = cnt.begin();
			if(last == it->first)it++;
			cur = it->first;
		}

		S.erase(make_pair(cnt[cur],cur));
		if(--cnt[cur]>0){
			S.insert(make_pair(cnt[cur],cur));
		}
		else if(i!=n)
			cnt.erase(it);

		printf("%d%c",cur,i==n?'\n':' ');
		last = cur;
	}
	return 0;
}

