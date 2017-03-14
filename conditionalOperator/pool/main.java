import java.util.Scanner;
import java.math.*;

import java.util.Scanner;
public class hello {
	public static int min (int a,int b){
		if (a>b)
			return b;
		else
			return a;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n,m,x,y,t = 0;
		
		n=in.nextInt();
		m=in.nextInt();
		x=in.nextInt();
		y=in.nextInt();
		if(n<m){t=n; n=m; m=t;}
		System.out.printf("%d",min(min(m - x, x), min(n- y, y)));
	}
	
}