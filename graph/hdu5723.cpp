/*************************************************************************
    > File Name: hdu5723.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Jun  4 16:47:17 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

const int maxm = 1e6+7;
const int maxn = 1e5+7;

typedef long long ll;

struct Edge{
	int from,to,len;
	int next;
}EdgeTable[maxm],EdgeList[2*maxn+100];
int fa[maxn];
int head[maxn];
int t,n,m,e;
double ans;
ll ans1;

bool comp(Edge a,Edge b)
{
	return a.len < b.len;
}

int find_fa(int cur)
{
	if(cur == fa[cur])return cur;
	else return fa[cur]=find_fa(fa[cur]);
}

int Dfs(int fa,int cur)
{
	int i;
	int all = 1;
	for(i=head[cur];i>=0;i=EdgeList[i].next){
		int ne = EdgeList[i].to;
		if(fa != ne){
			int siz = Dfs(cur,ne);
			all += siz;
			ans += (1.0*siz*(n-siz)*EdgeList[i].len)/(1.0*n*(n-1)/2);
		}
	}

	return all;
}

void addEdge(int from,int to, int len)
{
	EdgeList[e].from = from;
	EdgeList[e].to = to;
	EdgeList[e].next = head[from];
	EdgeList[e].len = len;
	head[from] = e++;
}

int main()
{
	freopen("input","r",stdin);
	cin >> t;
	while(t--){
		ans = 0.0;
		ans1 = 0;
		int tmp = 0;
		cin >> n >> m;
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&EdgeTable[i].from,&EdgeTable[i].to,&EdgeTable[i].len);
		sort(EdgeTable,EdgeTable+m,comp);
		for(int i=0;i<=n;i++){
			fa[i]=i;
		}

		memset(head,-1,sizeof(head));
		e=0;

		for(int i=0;i<m;i++){
			int a = EdgeTable[i].from;
			int b = EdgeTable[i].to;
			if(find_fa(a) != find_fa(b)){
				fa[b] = fa[a];
				addEdge(a,b,EdgeTable[i].len);
				addEdge(b,a,EdgeTable[i].len);
				ans1 += EdgeTable[i].len;
			}
			tmp++;
			if(tmp == n-1)break;
		}

		Dfs(-1,1);
		printf("%lld %.2f\n",ans1,ans);
	}
	return 0;
}


