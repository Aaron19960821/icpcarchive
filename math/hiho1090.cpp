/*************************************************************************
    > File Name: hiho1090.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Jan 21 15:15:01 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 1005

struct car{
	int x,y,l;
	int index;
}carlist[MAXN];

int n;
double ans[MAXN];
double tmptime[MAXN];
int yi[MAXN];

bool comp(car a,car b)
{
	return a.x>b.x;
}

int main()
{
	freopen("input","r",stdin);
	int i,xx,j;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&carlist[i].x,&carlist[i].y,&carlist[i].l);
		carlist[i].index = i;
		yi[i] = carlist[i].y;
		tmptime[i] = 0.0;
	}

	sort(carlist,carlist+n,comp);
	sort(yi,yi+n);

	for(i=0;i<n;i++){
		double tt = 0.0;
		xx = carlist[i].x;
		for(j=0;j<n;j++){
			if(yi[j]>xx){
				tt = tt + 1.0*(yi[j]-xx)/carlist[i].l;
				if(tt>tmptime[j])tmptime[j] = tt;
				else tt = tmptime[j];
				xx = yi[j];
				if(xx==carlist[i].y){
					ans[carlist[i].index] = tt;
					break;
				}
			}
		}
	}

	for(i=0;i<n;i++)
		printf("%.2lf\n",ans[i]);

	return 0;
}

