/*************************************************************************
    > File Name: hiho1103.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Jan 26 14:45:58 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

#define MAXN 1005

char taglist[3][10] = {"red","yellow","blue"};
stack<int>S;
char str[MAXN];
int ans[3];

int main()
{
	freopen("input","r",stdin);
	int i,j;

	gets(str);
	int len = strlen(str);
	i = 0;

	memset(ans,0,sizeof(ans));

	while(i<len){
		//cout << str[i] << endl;
		if(str[i]==' ');
		else if(str[i] == '<'){
			if(str[i+1]=='/'){
				i = i + strlen(taglist[S.top()])+3;
				S.pop();
			}
			else{
				for(j=0;j<3;j++){
					if(!strncmp(str+i+1,taglist[j],strlen(taglist[j]))){
						S.push(j);
						i = i + strlen(taglist[j]) + 2;
						break;
					}
				}
			}
			continue;

		}
		else if(!S.empty())ans[S.top()]++;
		i++;
	}

	for(i=0;i<3;i++){
		printf("%d%c",ans[i],i==2?'\n':' ');
	}

	return 0;
}

