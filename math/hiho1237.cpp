/*************************************************************************
    > File Name: hiho1237.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Jan 21 11:58:38 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

double x,y,r;

double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	int x_max,y_max;
	double dismax = -2.0;
	int left_most,right_most;

	cin >> x >> y >> r;
	left_most = ceil(x-r);
	right_most = floor(x+r);

	for(int i = right_most;i >= left_most; i--){
		double y_cur = y + sqrt(r*r-(x-i)*(x-i));
		int yc = floor(y_cur);
		double disc = dist(i,yc,x,y);
		if(disc>dismax){
			x_max = i;
			y_max = yc;
			dismax = disc;
		}

		y_cur = y - sqrt(r*r-(x-i)*(x-i));
		yc = ceil(y_cur);
		disc = dist(i,yc,x,y);
		if(disc>dismax){
			x_max = i;
			y_max = yc;
			dismax = disc;
		}
	}

	cout << x_max << " " << y_max << endl;
	return 0;
}

