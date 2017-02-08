/*************************************************************************
    > File Name: cf30c.java
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Wed Feb  8 22:04:19 2017
 ************************************************************************/

import java.util.*;
import java.io.*;

public class cf30c
{
	public static double[] dp;
	public static pair[] p;
	public static int n;

	public static void main(String[] argv)
	{
	/*	try{
			FileInputStream inp = new FileInputStream("input");
			System.setIn(inp);
		}
		catch(Exception e){}*/
		

		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		dp = new double[n+5];
		p = new pair[n];

		int i,j,k;
		double ans = 0.0;

		for(i=0;i<n;i++){
			p[i] = new pair(in.nextDouble(),in.nextDouble(),in.nextDouble(),in.nextDouble());
		}

		Arrays.sort(p);
		for(i=0;i<n;i++){
			for(j=i;j>=0;j--){
				if(p[i].t-p[j].t+1e-8>Dis(i,j)){
					dp[i] = Math.max(dp[i],dp[j]+p[i].p);
				}
			//	System.out.println(p[i].t-p[j].t+" "+Dis(i,j));
			}
			ans = Math.max(ans,dp[i]);
		}

		System.out.printf("%.8f\n",ans);
		return;
	}

	public static double Dis(int i,int j)
	{
		return Math.sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
	}
}

class pair implements Comparable<pair>
{
	public double x,y,t;
	public double p;

	public pair(double xx,double yy,double tt,double pp)
	{
		x = xx;
		y = yy;
		t = tt;
		p = pp;
	}

	public int compareTo(pair b)
	{
		return Double.compare(t,b.t);
	}
}
