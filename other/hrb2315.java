/*************************************************************************
    > File Name: hrb2315.java
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Sat Mar  4 17:48:30 2017
 ************************************************************************/

import java.util.*;

public class hrb2315
{
	public static int year,month,day,daylast;
	public static long secondlast;
	public static final int[] calendar = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	public static int t;

	public static boolean isLeap()
	{
		if(year%4==0 && year%100 != 0)
			return true;
		else if(year % 400 == 0)
			return true;
		else return false;
	}

	public static void Calyear()
	{
		int i;
		for(i=year;;i++){
			int dayinyear = 365;
			if(isLeap())dayinyear++;
			if(daylast<dayinyear){
				month = 1;
				day = 1;
				Calmonth();
				return;
			}
			year++;
			daylast -= dayinyear;
		}
	}


	public static void Calmonth()
	{
		int dayinmonth = 0, i;
		for(i=month;i<=12;i++){
			dayinmonth = calendar[i];
			if(month == 2 && isLeap())dayinmonth++;
			if(dayinmonth>=daylast){
				day = daylast+1;
				month = i;
				daylast = 0;
				break;
			}
			daylast -= dayinmonth;
		}
		if(daylast>0){
			year++;
			month = 1;
			day = 1;
			Calyear();
		}
		return;
	}

	public static void Calday()
	{
		int dayinmonth = calendar[month] - day + 1;
		if(month == 2 && isLeap())dayinmonth++;
		if(dayinmonth >= daylast){
			day += daylast;
			return;
		}
		else{
			daylast -= dayinmonth;
			month++;
			day = 1;
			Calmonth();
		}
	}

	public static void Output()
	{
		Calendar res = Calendar.getInstance();
		res.set(year,month-1,day);
		System.out.printf("%tF\n",res);
		return;
	}

	public static void main(String[] argv)
	{
		Scanner sc = new Scanner(System.in);
		
		t = sc.nextInt();
		while((t--)>0){
			String formatdate = sc.next();
			Scanner ss = new Scanner(formatdate);
			ss.useDelimiter("-");
		
			year = ss.nextInt();
			//System.out.println(year);
			month = ss.nextInt();
			//System.out.println(month);
			day = ss.nextInt();
			//System.out.println(day);
			secondlast = sc.nextLong();
			//System.out.println(secondlast);

			daylast = (int)secondlast/86400;

			Calday();
			Output();
		}
	}
}
