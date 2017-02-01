/*************************************************************************
    > File Name: hiho1260.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Jan 18 15:44:49 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 100005
#define MAXM 10005

struct TrieNode{
	char c;
	int isStop;
	int next[30];
}Trie[MAXN];

int n,m;
int e;
int isGet[MAXM],ans;

int create(int ch)
{
	++e;
	Trie[e].c = ch+'a';
	Trie[e].isStop = 0;
	memset(Trie[e].next,-1,sizeof(Trie[e].next));
	return e;
}

void add(int cur,int len,char* str,int id)
{
	if(!len){
		Trie[cur].isStop = id;
		return;
	}

	int ne = str[len-1] - 'a';
	if(Trie[cur].next[ne]<0)
		Trie[cur].next[ne] = create(ne);
	add(Trie[cur].next[ne],len-1,str,id);
	return;
}

int Dfs(int cur,int len,int isSub,char* str)
{
	//cout << cur  <<  " " <<  len << endl;
	if(!len && isSub){
		int tmp = Trie[cur].isStop;
		if(tmp>=0 && !isGet[tmp]){
			isGet[tmp] = 1;
			ans++;
			return 1;
		}
		else return 0;
	}
	else if(!len){
		int res = 0;
		for(int i=0;i<26;i++)
			if(Trie[cur].next[i]>=0)res += Dfs(Trie[cur].next[i],len,1,str);
		return res;
	}

	int res = 0;
	int ne = str[len-1] - 'a';

	if(Trie[cur].next[ne]>=0)res += Dfs(Trie[cur].next[ne],len-1,isSub,str);

	if(!isSub){
		for(int i = 0;i < 26;i++){
			if(Trie[cur].next[i]>=0)
				res += Dfs(Trie[cur].next[i],len,1,str);
		}
	}
	return res;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;

	char tmp[MAXN];
	
	scanf("%d%d",&n,&m);
	e = 0;
	memset(Trie[0].next,-1,sizeof(Trie[0].next));
	for(i=1;i<=n;i++){
		scanf("%s",tmp);
		add(0,strlen(tmp),tmp,i);
	}

	for(i=1;i<=m;i++){
		memset(isGet,0,sizeof(isGet));
		ans = 0;
		scanf("%s",tmp);
		Dfs(0,strlen(tmp),0,tmp);
		printf("%d\n",ans);
	}
	return 0;
}

