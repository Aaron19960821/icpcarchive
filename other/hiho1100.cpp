/*************************************************************************
    > File Name: hiho1100.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Jan 26 14:22:41 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define MAXN 100005

int h,r,n,m;
int Arr[MAXN];
vector<vector<int> >disklist;

int main()
{
	freopen("input","r",stdin);
	int i,j;
	int ans = 0;

	cin >> n >> m >> h >> r;
	for(i=1;i<=n;i++)scanf("%d",&Arr[i]);

	sort(Arr+1,Arr+n+1);
	
	for(i=1;i<=n;i++){
		if(i==1 || Arr[i]-Arr[i-1]>m){
			vector<int>tmp;
			tmp.push_back(Arr[i]);
			disklist.push_back(tmp);
		}
		else
			disklist[disklist.size()-1].push_back(Arr[i]);
	}

	for(i=disklist.size()-1;i>=0;i--){
		if(disklist[i][0]<=r){
			for(j=0;j<disklist[i].size();j++){
				if(disklist[i][j]>r+j)break;
				else ans++;
			}
			for(j=0;j<i;j++)ans += disklist[j].size();
			break;
		}
	}


	cout << min(ans,h) << endl;

	return 0;
}

