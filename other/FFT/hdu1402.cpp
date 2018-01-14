/*************************************************************************
    > File Name: hdu1402.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Thu Jun 15 18:57:29 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;

#define maxn 50005
const double PI = acos(-1.0);


struct Complex{
	double real,image;
	Complex(double _r, double _i){
		real = _r;
		image = _i;
	}
	Complex(){}

	Complex operator + (const Complex &b){
		return Complex(real+b.real,image+b.image);
	}

	Complex operator - (const Complex &b){
		return Complex(real-b.real,image-b.image);
	}

	Complex operator * (const Complex &b){
		return Complex(real*b.real-image*b.image,real*b.image+image*b.real);
	}
};

Complex num1[50005*3];
Complex num2[50005*3];
char s1[maxn],s2[maxn];
int N,pos;
int ans[50000*3];

int rev(int index,int len)
{
	int res = 0;
	for(int i = 0;(1<<i)<len;i++){
		res <<= 1;
		if(index & (1 << i))res |= 1;
	}
	return res;
}
void FFT(Complex* num,int len,int flag)
{
	int i,j;
	for(i=0;i<len;i++){
		if(i<rev(i,len))swap(num[i],num[rev(i,len)]);
	}

	for(int s=1,m=2;m<=len;++s,m*=2){
		Complex wm = Complex(cos(2*PI*flag/m),sin(2*PI*flag/m));
		for(i=0;i<len;i+=m){
			Complex w = Complex(1.0,0.0);
			for(j=0;j<m/2;j++){
				Complex u = num[i+j];
				Complex t = w*num[i+j+m/2];
				num[i+j] = u+t;
				num[i+j+m/2] = u-t;
				w = w*wm;
			}
		}
	}

	if(flag == -1){
		for(i=0;i<len;i++){
			num[i].real /= len;
			num[i].image /= len;
		}
	}
}

int main()
{
	freopen("input","r",stdin);
	int i;
	while(scanf("%s%s",s1,s2)!=EOF){
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(ans,0,sizeof(ans));
		N = 1;
		while(N<max(strlen(s1),strlen(s2)))N*=2;
		N *= 2;
		int len1 = strlen(s1),len2 = strlen(s2);

		for(i=len1-1;i>=0;i--)num1[len1-1-i] = Complex(s1[i]-'0',0.0);
		for(i=len2-1;i>=0;i--)num2[len2-1-i] = Complex(s2[i]-'0',0.0);
		for(i=len1;i<N;i++)num1[i] = Complex(0.0,0.0);
		for(i=len2;i<N;i++)num2[i] = Complex(0.0,0.0);

		FFT(num1,N,1);
		FFT(num2,N,1);

		for(i=0;i<N;i++)
			num1[i] = num1[i]*num2[i];
		FFT(num1,N,-1);

		N = pos = strlen(s1)+strlen(s2)+1;
		for(i=0;i<N;i++)ans[i] = num1[i].real+0.5;
		for(i=0;i<N;i++){
			if(ans[i]>=10){
				ans[i+1] += (ans[i]/10);
				ans[i] %= 10;
			}
		}
		for(i=pos;!ans[i]&&i>0;i--);
		for(;i>=0;i--)printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}

