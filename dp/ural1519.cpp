/*************************************************************************
    > File Name: ural1519.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Feb 19 20:39:59 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int hashs = 30007;
const int maxsize = 1000005;

int n,m;
int avl[15],code[15],ex,ey;
char maze[15][15];

struct hashmap
{
	int head[hashs],next[maxsize],size;
	LL state[maxsize],f[maxsize];
	void init()
	{
		size = 0;
		memset(head,-1,sizeof(head));
	}
	void push(LL s,LL num)
	{
		int h = s%hashs;
		int i;
		for(i=head[h];i!=-1;i=next[i]){
			if(state[i] == s){
				f[i] += num;
				return;
			}
		}
		state[size] = s;
		f[size] = num;
		next[size] = head[h];
		head[h] = size++;
		return;
	}
}hm[2];

void decode(int m,int* code,LL c)
{
	for(int i=m;i>=0;i--){
		code[i] = c&7;
		c = c>>3;
	}
}

void shift(int* code,int m)
{
	int i;
	for(i=m;i>0;i--)
		code[i] = code[i-1];
	code[0] = 0;
}

LL encode(int m,int* code)
{
	int i,ch[15],cnt=0;
	memset(ch,-1,sizeof(ch));
	ch[0] = 0;
	LL res = 0;
	for(i=0;i<=m;i++){
		if(ch[code[i]]<0)ch[code[i]]=++cnt;
		code[i] = ch[code[i]];
		res = res<<3;
		res += code[i];
	}
	return res;
}

void dpblank(int i,int j,int cur)
{
	int k,left,up,l;
	for(k=0;k<hm[cur].size;k++){
		decode(m,code,hm[cur].state[k]);
		left = code[j-1];
		up = code[j];
		if(left && up){
			if(left == up){
				if(i == ex && j==ey){
					code[j-1] = code[j] = 0;
					if(j==m)shift(code,m);
					hm[cur^1].push(encode(m,code),hm[cur].f[k]);
				}
			}
			else{
				code[j-1] = code[j] = 0;
				for(l=0;l<=m;l++){
					if(code[l] == up)
						code[l] = left;
				}
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(m,code),hm[cur].f[k]);
			}
		}
		else if((left&&!up) || (up&&!left)){
			int t;
			if(left)t = left;
			else t = up;
			if(maze[i+1][j] == '.'){
				code[j-1] = t;
				code[j] = 0;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(m,code),hm[cur].f[k]);
			}
			if(maze[i][j+1] == '.'){
				code[j] = t;
				code[j-1] = 0;
				if(j==m)shift(code,m);
				hm[cur^1].push(encode(m,code),hm[cur].f[k]);
			}
		}
		else{
			if(maze[i][j+1] == '.' && maze[i+1][j] == '.'){
				code[j] = code[j-1] = 13;
				hm[cur^1].push(encode(m,code),hm[cur].f[k]);
			}
		}
	}
}

void dpblock(int i,int j,int cur)
{
	int k;
	for(k=0;k<hm[cur].size;k++){
		decode(m,code,hm[cur].state[k]);
		code[j] = code[j-1] = 0;
		if(j==m)shift(code,m);
		hm[cur^1].push(encode(m,code),hm[cur].f[k]);
	}
}

void Solve()
{
	int cur = 0, i ,j;
	hm[cur].init();
	hm[cur].push(0,1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			//cout << hm[cur].size << endl;
			hm[cur^1].init();
			if(maze[i][j] == '*')
				dpblock(i,j,cur);
			else dpblank(i,j,cur);
			cur = cur^1;
		}
	}

	LL ans = 0;
	for(i=0;i<hm[cur].size;i++)
		ans += hm[cur].f[i];
	cout << ans << endl;
}

int main()
{
	//freopen("input","r",stdin);
	int i,j;

	cin >> n >> m;
	for(i=1;i<=n;i++){
		scanf("%s",maze[i]+1);
		for(j=1;j<=m;j++){
			if(maze[i][j] == '.'){
				ex = i;
				ey = j;
			}
		}
	}

	Solve();
}

