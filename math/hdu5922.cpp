/*************************************************************************
    > File Name: hdu5922.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Jun  8 19:34:57 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int t,n;

int main()
{
	int ncase = 0;
	cin >> t;
	while(t--){
		cin >> n;
		cout << "Case #" << ++ncase << ": " ;
		cout << 1ll*(n+1)*n/2-1 << endl;
	}
	return 0;
}

