/*************************************************************************
    > File Name: cf119c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Feb  9 20:04:33 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

const int maxn = 55;
#define LL long long

struct course
{
	LL a,b;
	int c;
	int id;
}cl[maxn];

int n,m,k;
LL dp[maxn][maxn][105];
pair<int,int>pre[maxn][maxn][105];

bool comp(course a, course b)
{
	return a.c < b.c;
}

void backtrack(int index,int last,int offset)
{
	if(last == 1){
		cout << cl[index].id << " " << cl[index].a + offset << endl;
		return;
	}
	LL next;
	int nindex = pre[index][last][offset].first;
	if(pre[index][last][offset].second==0)
		next = cl[index].a + offset - k - cl[nindex].a;
	else
		next = (cl[index].a + offset)/k - cl[nindex].a;
	backtrack(nindex,last-1,next);
	cout << cl[index].id << " " << cl[index].a + offset << endl;
	return;
}

int main()
{
	//freopen("input","r",stdin);
	int i,j,h,g;

	cin >> m >> n >> k;
	for(i=1;i<=n;i++){
		scanf("%lld%lld%d",&cl[i].a,&cl[i].b,&cl[i].c);
		cl[i].id = i;
	}

	sort(cl+1,cl+n+1,comp);
	memset(dp,-1,sizeof(dp));

	for(i=1;i<=n;i++){
		for(j=0;j<=cl[i].b-cl[i].a;j++){
			dp[i][1][j] = cl[i].a + j;
			pre[i][1][j].first = -1;
		}

		for(j=1;j<=min(i,m);j++){
			for(h=0;h<=cl[i].b-cl[i].a;h++){
				for(g=i+1;g<=n;g++){
					if(cl[g].c > cl[i].c && dp[i][j][h] != -1){
						LL next = k + h + cl[i].a-cl[g].a;
						if(next>=0 && next <= cl[g].b-cl[g].a && dp[g][j+1][next]<dp[i][j][h]+next+cl[g].a){
							dp[g][j+1][next] = dp[i][j][h] + next + cl[g].a;
							pre[g][j+1][next].first = i;
							pre[g][j+1][next].second = 0;
						}
						next = k*(h + cl[i].a)-cl[g].a;
						if(next>=0 && next <= cl[g].b-cl[g].a && dp[g][j+1][next]<dp[i][j][h]+next+cl[g].a){
							dp[g][j+1][next] = dp[i][j][h] + next + cl[g].a;
							pre[g][j+1][next].first = i;
							pre[g][j+1][next].second = 1;
						}
					}
				}
			}
		}
	}

	int offset = -1, s = -1;
	for(i=n;i>=m;i--){
		for(j=0;j<=cl[i].b-cl[i].a;j++){
			if(dp[i][m][j] < 0)continue;
			if(offset<0 || dp[i][m][j]>dp[s][m][offset]){
				offset = j;
				s = i;
			}
		}
	}

	if(offset<0)
		cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		backtrack(s,m,offset);
	}

	return 0;
}

