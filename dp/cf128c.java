/*************************************************************************
    > File Name: cf128c.java
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Feb 11 15:33:03 2017
 ************************************************************************/

import java.util.*;
import java.io.*;

public class cf128c
{
	public static final int mod = 1000000007;
	public static int n,m,k;
	public static long[][] dp;

	public static void main(String[] argv)
	{
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		int i,j;

		dp = new long[2005][2005];

		for(i=1;i<=2000;i++){
			dp[i][0] = 1;
			for(j=1;j<=i;j++)
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
		}

		long ans = (dp[n][2*k]*dp[m][2*k])%mod;
		System.out.println(ans);
		return;
	}
}
