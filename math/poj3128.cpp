/*************************************************************************
    > File Name: poj3128.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Mar  2 20:50:17 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int t;

char s[30];
int vis[30];
int vv[30];

int main()
{
	freopen("input","r",stdin);
	int i;
	cin >> t;
	while(t--){
		int flag = 1;
		memset(vis,0,sizeof(vis));
		memset(vv,0,sizeof(vv));
		scanf("%s",s);
		for(i=0;i<26;i++){
			if(!vis[i]){
				vis[i]=1;
				int ss = 1;
				int j = s[i]-'A';
				while(j!=i){
					vis[j]=1;
					ss++;
					j = s[j]-'A';
				}
				if(!(ss&1)){
					if(vv[ss])vv[ss]=0;
					else vv[ss]=1;
				}
			}
		}
		for(i=0;i<30;i++)
			if(vv[i]){
				flag = 0;
				break;
			}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

