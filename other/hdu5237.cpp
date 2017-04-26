/*************************************************************************
    > File Name: hdu5237.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sun Apr 23 20:28:27 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1005;

int ncase = 0, T;
int k;
char s[maxn];
char ss[maxn];
int now;

char lookup(int index)
{
	if(index<26)return 'A'+index;
	else if(index < 52)return 'a'+index-26;
	else if(index < 62)return '0'+index-52;
	else if(index == 62)return '+';
	else return '/';
}

void transbase64(int state, int num)
{
	int i;
	for(i=num-1;i>=0;i--){
		int cur = state & (0x3f);
		state = state >> 6;
		ss[now+i] = lookup(cur);
	}
	for(i=num;i<4;i++)
		ss[now+i] = '=';
	now += 4;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	cin >> T;
	while(T--){
		printf("Case #%d: ",++ncase);
		cin >> k >> s;
		int l = strlen(s);

		for(i=0;i<k;i++){
			now = 0;
			for(j = 0;j < l && j+2 <l; j += 3){
				int numlen = 0;
				numlen = (int)s[j];
				numlen = numlen << 8;
				numlen |= (int)s[j+1];
				numlen = numlen << 8;
				numlen |= (int)s[j+2];
				transbase64(numlen,4);
			}

			if(l % 3 == 1){
				int numlen = 0;
				numlen = (int)s[l-1];
				numlen = numlen << 4;
#ifdef TEST
				cout << transbase64(numlen,2);
#endif
				transbase64(numlen,2);
			}
			else if(l % 3 == 2){
				int numlen = (int)s[l-2];
				numlen = numlen << 8;
				numlen |= (int)s[l-1];
				numlen = numlen << 2;
#ifdef TEST
				cout << transbase64(numlen,3);
#endif
				transbase64(numlen,3);
			}

			if(l%3 != 0){
				l = l/3*4+4;
			}
			else
				l = l/3*4;
			for(j=0;j<l;j++)
				s[j] = ss[j];
			s[j] = '\0';
		}
		cout << s << endl;
	}
	return 0;
}
