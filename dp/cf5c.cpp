/*************************************************************************
    > File Name: cf5c.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb  7 22:12:33 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;

#define MAXN 1000005

char s[MAXN];
int open[MAXN],isde[MAXN];

int main()
{
	//freopen("input","r",stdin);
	int i,j;
	stack<int>S;
	memset(open,0,sizeof(open));

	scanf("%s",s);
	int l = strlen(s);
	memset(open,-1,sizeof(open));

	for(i=0;i<l;i++){
		if(s[i] == '(')
			S.push(i);
		else{
			if(!S.empty()){
				open[S.top()] = i;
				S.pop();
			}
			else{
				open[i] = -1;
			}
		}
	}

	int ans1 = 0,ans2 = 1, cur = 0;
	for(i=0;i<l;i++){
		if(open[i]!=-1){
			cur += open[i] - i + 1;
			if(ans1<cur){
				ans1 = cur;
				ans2 = 1;
			}
			else if(cur == ans1)ans2++;
			i = open[i];
		}
		else cur = 0;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}

