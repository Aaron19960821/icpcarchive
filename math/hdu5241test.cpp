/*************************************************************************
    > File Name: hdu5241test.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Mon May  1 10:51:54 2017
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
const int maxn = 30050 ;
const int mod = 100 ;
int num[maxn] ;
int len ;
int solve(int  n)
{
    memset(num , 0 , sizeof(num)) ;
    num[1] = 1;len = 1;
    for(int i = 1;i <=n ;i++)
    {
        int c = 0 ;
        for(int j = 1;j <= len; j++)
        {
            num[j] *= 32 ;
            num[j] += c ;
            c = num[j]/mod ;
            num[j] %= mod ;
        }
        while(c)
        {
            num[++len] = c%mod ;
            c/=mod ;
        }
    }
}
int main()
{
    int T ;
    int cas =0 ;
    scanf("%d" , &T) ;
    while(T--)
    {
        int n  ;
        scanf("%d" , &n) ;
        solve(n) ;
        printf("Case #%d: " , ++cas) ;
        for(int i = len;i > 0;i--)
        {
            if(i!=len)
            printf("%02d" ,num[i]) ;
            else
            printf("%d" , num[i]) ;
        }
        puts("") ;
    }
}
