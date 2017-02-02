/*************************************************************************
    > File Name: hiho1102.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Jan 25 20:31:59 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

double rate[10] = {0.03,0.1,0.2,0.25,0.3,0.35,0.45};
double maxtax[10] = {0.0,45.0,300.0,900.0,6500.0,6000.0,8750.0};
double st[10] = {0,1500,4500,9000,35000,55000,80000};
double tax,ans;

int main()
{
	int i;

	for(i=1;i<=6;i++)maxtax[i] += maxtax[i-1];

	cin >> tax;
	ans = 0;

	for(i=6;i>=0;i--){
		if(tax>maxtax[i]){
			ans = st[i] + (tax-maxtax[i])/rate[i];
			//cout << ans << endl;
			break;
		}
	}

	printf("%d\n",(int)(ans+0.1)+3500);
	return 0;
}

