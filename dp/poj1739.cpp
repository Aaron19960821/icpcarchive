/*************************************************************************
    > File Name: poj1739.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb 21 20:05:26 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;

const int maxn = 20;
const int hashsize = 301;
const int sizes = 10005;

char grid[maxn][maxn];
int n,m,code[maxn];

struct hashmap
{
	int size,head[hashsize],next[sizes];
	LL states[sizes];
	LL f[sizes];

	void init()
	{
		size = 0;
		memset(head,-1,sizeof(head));
	}

	void push(LL state,LL num)
	{
		int h = state%hashsize;
		int i;
		for(i=head[h];i>=0;i=next[i])
			if(states[i] == state){
				f[i] += num;
				return;
			}
		states[size] = state;
		next[size] = head[h];
		f[size] = num;
		head[h] = size++;
		return;
	}
}hm[2];

void shift(int* code,int m)
{
	for(int i = m;i > 0;i--)
		code[i] = code[i-1];
	code[0] = 0;
	return;
}

LL encode(int* code,int m)
{
	LL res = 0;
	int i,ch[20],cnt=0;
	memset(ch,-1,sizeof(ch));
	ch[0]=0;
	for(i=0;i<=m;i++){
		if(ch[code[i]]<0)ch[code[i]] = ++cnt;
		code[i] = ch[code[i]];
		res = res<<3;
		res += code[i];
	}
	return res;
}

void decode(int* code,int m,LL c)
{
	int i;
	for(i=m;i>=0;i--){
		code[i] = c&7;
		c = c>>3;
	}
}

void dpblock(int i,int j,int cur)
{
	int k;

	for(k=0;k<hm[cur].size;k++){
		decode(code,m,hm[cur].states[k]);
		code[j] = code[j-1] = 0;
		if(j==m)shift(code,m);
		hm[cur^1].push(encode(code,m),hm[cur].f[k]);
	}
	return;
}

void dpblank(int i,int j,int cur)
{
	int k,left,up,l;
	for(k=0;k<hm[cur].size;k++){
		decode(code,m,hm[cur].states[k]);
		left = code[j-1]; up = code[j];
		if((i==n&&j==1) || (i==n&&j==m)){
			if((!left&&up)||(!up&&left)){
				code[j-1] = code[j] = 0;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(code,m),hm[cur].f[k]);
			}
			else if(!left && !up){
				if(grid[i][j+1] == '.'){
					code[j] = 10;
					code[j-1] = 0;
					if(j==m)shift(code,m);
					hm[cur^1].push(encode(code,m),hm[cur].f[k]);
				}
			}
			continue;
		}

		if(left&&up){
			if(left != up){
				code[j-1] = code[j] = 0;
				for(l=0;l<=m;l++)
					if(code[l] == left)
						code[l] = up;
				if(j == m)shift(code,m);
				hm[cur^1].push(encode(code,m),hm[cur].f[k]);
			}
		}
		else if((!left&&up)||(!up&&left)){
			int t;
			if(left>0)t = left;
			else t = up;
			if(grid[i+1][j] == '.'){
				code[j-1] = t; code[j]=0;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(code,m),hm[cur].f[k]);
			}
			if(grid[i][j+1] == '.'){
				code[j] = t; code[j-1]=0;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(code,m),hm[cur].f[k]);
			}
		}
		else{
			if(grid[i][j+1] == '.' && grid[i+1][j] == '.'){
				code[j] = code[j-1] = 13;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(code,m),hm[cur].f[k]);
			}
		}

	}
}

void solve()
{
	int cur = 0,i,j;
	hm[cur].init();
	hm[cur].push(0,1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
		//	cout << hm[cur].size << endl;
			hm[cur^1].init();
			if(grid[i][j] == '.')
				dpblank(i,j,cur);
			else 
				dpblock(i,j,cur);
			cur = cur^1;
		}
	}

	LL ans = 0;
	for(i=0;i<hm[cur].size;i++)
		ans += hm[cur].f[i];
	cout << ans << endl;
	//cout <<"____" << endl;
	return;
}

int main()
{
	freopen("input","r",stdin);
	int i;
	while(1){
		cin >> n >> m;
		memset(grid,0,sizeof(grid));
		if(!n && !m)break;
		for(i=1;i<=n;i++)
			scanf("%s",grid[i]+1);
		solve();
	}
	return 0;
}

