/*************************************************************************
    > File Name: cf765e.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb 14 22:08:13 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 200005;

vector<int>grid[maxn];
int n;
int sub;

int Dfs(int pre,int cur)
{
	vector<int>d;
	int i;

	for(i=0;i<grid[cur].size();i++){
		int des = grid[cur][i];
		if(des != pre){
			int tmp = Dfs(cur,des);
			if(tmp >= 0)d.push_back(tmp+1);
			else return -1;
		}
	}

	sort(d.begin(),d.end());
	d.erase(unique(d.begin(),d.end()),d.end());

	int s = d.size();
	if(!s)return 0;
	else if(s == 1)return d[0];
	else if(s == 2 && pre == -1)return d[0] + d[1];
	sub = cur;
	return -1;
}

int solve()
{
	int ans = Dfs(-1,1);
	if(ans < 0){
		ans = Dfs(-1,sub);
	}

	if(ans < 0)return -1;
	else{
		while(!(ans & 1))ans = ans >> 1;
		return ans;
	}

}

int main()
{
	//freopen("input","r",stdin);
	int i,tmp1,tmp2;

	cin >> n;
	for(i=0;i<n-1;i++){
		scanf("%d%d",&tmp1,&tmp2);
		grid[tmp1].push_back(tmp2);
		grid[tmp2].push_back(tmp1);
	}

	cout << solve() << endl;
	return 0;
}

