/*************************************************************************
    > File Name: hdu4861.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Jun  7 11:00:51 2017
 ************************************************************************/

#include<iostream>
using namespace std;

int k,p;

int main()
{
	while(scanf("%d%d",&k,&p)!=EOF){
		int tmp = k/(p-1);
		if(tmp&1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

