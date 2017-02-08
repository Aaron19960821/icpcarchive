/*************************************************************************
    > File Name: cf5c.java
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Tue Feb  7 21:31:22 2017
 ************************************************************************/

import java.io.*;
import java.util.*;

public class cf5c
{
	public static void main(String[] args)
	{
		try{
			FileInputStream f = new FileInputStream("input");
			System.setIn(f);
		}
		catch(Exception e){
		}

		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();

		int l = s.length(),i,j,k;
		int curleft = 0, curlen = 0, ans1 = 0, ans2 = 1;
		System.out.println(s);

		for(i=0;i<l;i++){
			if(s.charAt(i) == '('){
				curleft++;
			}
			else{
				if(curleft>0){
					curleft--;
					curlen += 2;
					if(curleft == 0){
						if(curlen == ans1)ans2++;
						else if(curlen > ans1){
							ans1 = curlen;
							ans2 = 1;
						}
					}
				}
				else{
					curlen = 0;
				}
			}
			System.out.println(curlen);
		}
		System.out.println(ans1 + " " +ans2);
		return;
	}
}
