/*************************************************************************
    > File Name: scut2017J.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Apr 30 15:47:11 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e5+7;
typedef long long ll;

struct soldier{
	int a,b,c;
}sollist[maxn];
ll ans;
int n,k,t;

bool cmp(soldier a,soldier b)
{
	if(a.b == b.b)return a.a>b.a;
	else return a.b>b.b;
}

bool cmp1(soldier a,soldier b)
{
	return (a.a+a.b-a.c) > (b.a+b.b-b.c);
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n >> k;
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&sollist[i].a,&sollist[i].b,&sollist[i].c);
			ans += sollist[i].c;
		}

		sort(sollist+1,sollist+n+1,cmp);

		ans += (sollist[1].a+sollist[1].b-sollist[1].c);
		k--;

		sort(sollist+2,sollist+n+1,cmp1);

		for(i=2;i<=n&&k;i++,k--){
			if(sollist[i].a+sollist[i].b-sollist[i].c < sollist[1].b)
				break;
			ans += (sollist[i].a + sollist[i].b - sollist[i].c);
		}

		ans += k*sollist[1].b;

		cout << ans << endl;

	}
	return 0;
}


