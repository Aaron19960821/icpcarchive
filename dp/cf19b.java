/*************************************************************************
    > File Name: cf19b.java
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Feb 10 18:16:32 2017
 ************************************************************************/

import java.util.*;
import java.io.*;

public class cf19b
{
	public static int[] t;
	public static int[] c;
	public static int n;
	public static long[] dp;
	public static void main(String[] argv)
	{
	/*	try{
			FileInputStream inp = new FileInputStream("input");
			System.setIn(inp);
		}
		catch(Exception e){}*/
		Scanner in = new Scanner(System.in);

		n = in.nextInt();
		t = new int[n+1];
		c = new int[n+1];
		dp = new long[n+2];

		int i,j;
		Arrays.fill(dp,(long)(1e+15));

		for(i=1;i<=n;i++){
			t[i] = in.nextInt() + 1;
			c[i] = in.nextInt();
		}

		dp[0] = 0;
		for(i=1;i<=n;i++){
			for(j=n;j>=0;j--){
				dp[j] = Math.min(dp[j+1],Math.min(dp[j],dp[Math.max(0,j-t[i])]+c[i]));
			}
		}

		System.out.println(dp[n]);
		return;
	}
}
