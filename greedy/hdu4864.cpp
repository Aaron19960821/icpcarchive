/*************************************************************************
    > File Name: hdu4864.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Jun  6 11:25:09 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

vector<int>tasks[1450];
vector<int>machine[1450];
int n,m;
int cur[105];
ll ans2;
int ans1;

void Init()
{
	for(int i=0;i<1450;i++){
		tasks[i].clear();
		machine[i].clear();
	}
	ans1 = ans2 = 0;
	memset(cur,0,sizeof(cur));
}

int main()
{
	freopen("input","r",stdin);
	int i,j,k;
	int tmp1,tmp2;
	while(scanf("%d%d",&n,&m)!=EOF){
		Init();
		for(i=0;i<n;i++){
			scanf("%d%d",&tmp1,&tmp2);
			machine[tmp1].push_back(tmp2);
		}
		for(i=0;i<m;i++){
			scanf("%d%d",&tmp1,&tmp2);
			tasks[tmp1].push_back(tmp2);
		}
		for(i=1440;i>=0;i--){
			//cout << i << " " << tasks[i].size() << endl;
			for(j=0;j<machine[i].size();j++)cur[machine[i][j]]++;
			if(tasks[i].size()>0){
				sort(tasks[i].begin(),tasks[i].end());
				for(j=tasks[i].size()-1;j>=0;j--){
					for(k=tasks[i][j];k<=100;k++){
						if(cur[k]>0){
							cur[k]--;
							ans1++;
							ans2 += (500*i+2*tasks[i][j]);
							break;
						}
					}
				}
			}
		}

		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

