/*************************************************************************
    > File Name: cf73c.java
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Feb  8 20:17:12 2017
 ************************************************************************/

import java.util.*;
import java.io.*;

public class cf73c
{
	public static int[][] charmap;
	public static int n,k;
	public static String s;
	public static int[][][] dp;
	public static void main(String[] argv)
	{
		/*try{
			FileInputStream inp = new FileInputStream("input");
			System.setIn(inp);
		}
		catch(Exception e){}
		*/
		Scanner in = new Scanner(System.in);
		s = in.next();
		k = in.nextInt();
		n = in.nextInt();

		int i,j;
		charmap = new int[27][27];
		for(i=0;i<27;i++){
			Arrays.fill(charmap[i],0);
		}

		for(i=0;i<n;i++)
			charmap[in.next().charAt(0)-'a'][in.next().charAt(0)-'a'] = in.nextInt();

		dp = new int[s.length()+1][27][k+5];

		for(i=0;i<s.length();i++){
			for(j=0;j<27;j++){
				Arrays.fill(dp[i][j],-1000000000);
			}
		}

		System.out.println(Dfs(0,26,k));
		return;
	}

	public static int Dfs(int i,int pre,int last)
	{
		if(last < 0)return -1000000000;
		if(i == s.length())return 0;
		if(dp[i][pre][last] != -1000000000)return dp[i][pre][last];
		dp[i][pre][last] = Dfs(i+1,s.charAt(i)-'a',last) + charmap[pre][s.charAt(i)-'a'];
		int j;
		for(j=0;j<26;j++){
			dp[i][pre][last] = Math.max(dp[i][pre][last],Dfs(i+1,j,last-1)+charmap[pre][j]);
		}
		return dp[i][pre][last];
	}
}
