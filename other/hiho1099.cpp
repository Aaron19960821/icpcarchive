/*************************************************************************
    > File Name: hiho1099.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Jan 25 19:57:21 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;

struct constell{
	int h,w;
	vector<pair<int,int> >p;
}conset[25];

int k;
char sky[105][1005];
int N,M;
int isSee[25];

int Judge(int x,int y){
	if(x>N||y>=M||x<=0||y<0||sky[x][y]=='.')return 0;
	return 1;
}

int main()
{
	freopen("input","r",stdin);
	int i,j,t,g;
	char tmp[105];

	memset(isSee,0,sizeof(isSee));
	scanf("%d",&k);
	for(i=1;i<=k;i++){
		cin >> conset[i].h >> conset[i].w;
		for(j=1;j<=conset[i].h;j++){
			scanf("%s",tmp);
			for(t=0;t<conset[i].w;t++){
				if(tmp[t] == '#')
					conset[i].p.push_back(make_pair(j,t));
			}
		}
	}

	cin >> N >> M;
	for(i=1;i<=N;i++)scanf("%s",sky[i]);

	for(i=1;i<=N;i++){
		for(j=0;j<M;j++){
			if(sky[i][j] == '#'){
				for(t=1;t<=k;t++){
					int flag = 1;
					if(!isSee[t]){
						for(g=1;g<conset[t].p.size();g++){
							if(!Judge(i+conset[t].p[g].first-conset[t].p[0].first,j+conset[t].p[g].second-conset[t].p[0].second)){
								flag = 0;
								break;
							}
						}
					}
					isSee[t] = flag;
				}
			}
		}
	}

	for(i=1;i<=k;i++){
		if(isSee[i])cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

