/*************************************************************************
    > File Name: hiho1489.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Apr  1 20:59:48 2017
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

double call_exp(int p,int q)
{
	int i;
	double res = 1.0;
	double tmpnot = 1.0;
	double double_p = 1.0*p/100;
	double double_q = 1.0*q/100;

	for(i=1;i<=100;i++){
		tmpnot *= (1-double_p);
		res += tmpnot;
		double_p += double_q;
		if(double_p >= 1.0)break;
	}
	

	return res;
}

int main()
{
	int P,Q,N;
	int i;
	double ans = 0.0;

	cin >> P >> Q >> N;

	for(i=0;i<N;i++){
		//cout << call_exp(P>>i,Q) << endl;
		ans += call_exp(P,Q);
		P = P>>1;
	}

	printf("%.2f\n",ans);
	return 0;
}

