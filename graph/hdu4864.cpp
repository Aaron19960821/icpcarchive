/*************************************************************************
    > File Name: hdu4864.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon Jun  5 23:10:57 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e5+7;
typedef long long ll;

struct mach{
	int x,y;
	friend bool operator<(mach a,mach b){
		if(a.x == b.x)return a.y < b.y;
		return a.x < b.x;
	}
}machine[maxn],task[maxn];

int n,m;
ll ans1;
int ans2;

int main()
{
//	freopen("input","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)scanf("%d%d",&machine[i].x,&machine[i].y);
		for(int i=0;i<m;i++)scanf("%d%d",&task[i].x,&task[i].y);

		sort(machine,machine+n);
		sort(task,task+m);

		ans1 = ans2 = 0;
		int i = 0,j = 0;
		while(i<n && j<m){
			if(machine[i].x >= task[j].x && machine[i].y >= task[j].y){
				i++;j++;
				ans1 += (500*task[j].x+2*task[j].y);
				ans2++;
			}
			else j++;
		}

		cout << ans2 << " " << ans1 << endl;
	}
	return 0;
}

