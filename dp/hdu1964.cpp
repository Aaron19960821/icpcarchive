/*************************************************************************
    > File Name: hdu1964.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Feb 22 19:18:43 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

#define right first
#define down second

typedef long long LL;

const int hashsize = 30005;
const int sizes = 1000010;

int t,n,m;
pair<int,int>grid[15][15];

struct hashmap
{
	int size,head[hashsize],next[sizes];
	LL f[sizes],states[sizes];
	void init()
	{
		size = 0;
		memset(head,-1,sizeof(head));
	}

	void push(long long state,LL num)
	{
		int h = state%hashsize;
		int i;
		for(i=head[h];i>=0;i=next[i]){
			if(states[i] == state){
				f[i] = min(f[i],num);
				return;
			}
		}
		f[size] = num;
		states[size] = state;
		next[size] = head[h];
		head[h] = size++;
	}
}hm[2];

void decode(int* code,int m,long long c)
{
	int i;
	for(i=m;i>=0;i--){
		code[i] = c&7;
		c = c>>3;
	}
}

long long encode(int* code,int m)
{
	int i,ch[20],cnt=0;
	long long res = 0;
	memset(ch,-1,sizeof(ch));
	ch[0] = 0;
	for(i=0;i<=m;i++){
		if(ch[code[i]]<0)ch[code[i]] = ++cnt;
		code[i] = ch[code[i]];
		res = res<<3;
		res += code[i];
	}
	return res;
}

void shift(int* code,int m)
{
	int i;
	for(i=m;i>0;i--)
		code[i] = code[i-1];
	code[0] = 0;
}

void initi()
{
	char s[30];
	int i,j;
	memset(grid,0,sizeof(grid));
	gets(s);
	for(i=1;i<n;i++){
		gets(s);
		for(j=1;j<m;j++)
			grid[i][j].right = s[2*j]-'0';
		gets(s);
		for(j=1;j<=m;j++)
			grid[i][j].down = s[2*j-1]-'0';
	}
	gets(s);
	for(j=1;j<m;j++)
		grid[n][j].right = s[2*j]-'0';
	gets(s);
	return;
}

void dpblank(int i,int j,int cur)
{
	int code[15],k,left,up,l;
	for(k=0;k<hm[cur].size;k++){
		decode(code,m,hm[cur].states[k]);
		left = code[j-1];
		up = code[j];

		if(left && up){
			if(left == up){
				if(i == n && j == m){
					code[j-1] = code[j] = 0;
					shift(code,m);
					hm[cur^1].push(encode(code,m),hm[cur].f[k]);
				}
			}
			else{
				code[j-1] = code[j] = 0;
				for(l=0;l<=m;l++)
					if(code[l] == left)
						code[l] = up;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(code,m),hm[cur].f[k]);
			}
		}
		else if((left&&!up)||(up&&!left)){
			int t;
			if(left)t = left;
			else t = up;
			if(j < m){
				code[j-1] = 0; code[j] = t;
				hm[cur^1].push(encode(code,m),hm[cur].f[k]+grid[i][j].right);
			}
			if(i < n){
				code[j-1] = t; code[j] = 0;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(code,m),hm[cur].f[k]+grid[i][j].down);
			}
		}
		else{
			if(i<n&&j<m){
				code[j-1] = code[j] = 15;
				hm[cur^1].push(encode(code,m),hm[cur].f[k]+grid[i][j].right+grid[i][j].down);
			}
		}
	}
}

void solve()
{
	int i,j,cur=0;
	hm[cur].init();
	hm[cur].push(0,0);

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
		//	cout << hm[cur].size << endl;
			hm[cur^1].init();
			dpblank(i,j,cur);
			cur = cur^1;
		}
	}

	//LL ans = hm[cur].f[0];
	//for(i=1;i<hm[cur].size;i++)
	//	ans = min(ans,hm[cur].f[i]);
	cout << hm[cur].f[0] << endl;
	//cout << "___" << endl;
	return;
}

int main()
{
	freopen("input","r",stdin);
	cin >> t;
	while(t--){
		cin >> n >> m;
		getchar();
		initi();
		solve();
	}
	return 0;
}
