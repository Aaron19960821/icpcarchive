/*************************************************************************
    > File Name: cf111c.java
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Feb 11 16:51:01 2017
 ************************************************************************/

import java.util.*;
import java.io.*;

public class cf111c
{
	public static int n,m,maxm;
	public static int[][][] dp;
	public static int[] s;


	public static int cal(int cur)
	{
		int res = 0;
		while(cur>0){
			res ++;
			cur = cur&(cur-1);
		}
		return res;
	}

	public static boolean check(int a,int b,int c)
	{
		int res = (maxm-1) & (b | (b<<1) | (b>>1) | a | c);
		if(res == maxm-1)return true;
		else return false;
	}

	public static void main(String[] argv)
	{
		Scanner in = new Scanner(System.in);

		n = in.nextInt();
		m = in.nextInt();
		if(n<m){
			int t = m;
			m = n;
			n = t;
		}

		maxm = 1<<m;
		int i,j,k,l;
		dp = new int[n+1][1<<m][1<<m];
		s = new int[1<<m];

		for(i=0;i<n+1;i++){
			for(j=0;j<maxm;j++){
				Arrays.fill(dp[i][j],100);
			}
		}

		for(i=0;i<maxm;i++){
			s[i] = cal(i);
			dp[0][0][i] = 0;
		}

		for(i=1;i<=n;i++){
			for(j=0;j<maxm;j++){
				for(k=0;k<maxm;k++){
					for(l=0;l<maxm;l++){
						if(dp[i-1][k][l]!=100 && check(k,l,j)){
							dp[i][l][j] = Math.min(dp[i-1][k][l]+s[l],dp[i][l][j]);
						}
					}
				}
			}
		}

		int ans = 100;
		for(i=0;i<maxm;i++)
			ans = Math.min(dp[n][i][0],ans);

		System.out.println(n*m-ans);
		return;
	}
}
