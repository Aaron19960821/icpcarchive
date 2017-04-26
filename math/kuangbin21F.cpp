/*************************************************************************
    > File Name: kuangbin21F.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Apr 26 22:15:26 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 105;
const double EPS = 1e-7;

int trans[maxn];
double mat[maxn][maxn];
int T,n;

void Gauss()
{
	int i,j;
	for(i=1;i<=100;i++){
		int max_l = i;
		for(j=i;j<=100;j++){
			if(fabs(mat[j][i]) > fabs(mat[max_l][i]))
				max_l = j;
		}

		for(j=0;j<maxn;j++)
			swap(mat[max_l][j],mat[i][j]);

		for(j=i+1;j<=100;j++){
			if(fabs(mat[j][i]) > EPS){
				double pivot = mat[j][i]/mat[i][i];
				for(int k=0;k<=101;k++)
					mat[j][k] -= pivot*mat[i][k];
			}
		}
	}

	for(i=100;i>0;i--){
		for(j=i+1;j<=100;j++){
			mat[i][101] -= mat[j][101]*mat[i][j];
		}
		mat[i][101] /= mat[i][i];
	}
	return;
}

int main()
{
	freopen("input","r",stdin);
	int i,j;
	int a,b;
	int ncase;
	cin >> T;

	for(ncase=1;ncase<=T;ncase++){
		printf("Case %d: ",ncase);
		memset(trans,-1,sizeof(trans));
		memset(mat,0,sizeof(mat));

		cin >> n;
		for(i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			trans[a] = b;
		}

		mat[100][100] = 1.0;
		mat[100][101] = 0.0;
		//create the matrix
		for(i=1;i<100;i++){
			if(trans[i] > 0){
				mat[i][i] = 1.0;
				mat[i][trans[i]] = -1.0;
				mat[i][101] = 0.0;
			}
			else{
				a = 0;
				for(j=1;j<=6;j++){
					if(i+j<=100){
						mat[i][i+j] = -1.0;
						a++;
					}
				}
				mat[i][i] = a;
				mat[i][101] = 6.0;
			}
		}

		Gauss();
		printf("%.7f\n",mat[1][101]);
	}
	return 0;
}

