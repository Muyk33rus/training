import java.util.Scanner;
import java.math.*;

import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b,c,t;

		a=in.nextInt();
		b=in.nextInt();
		c=in.nextInt();
		if(a>b){t=a; a=b; b=t;}
		if(a>c){t=a; a=c; c=t;}
		if(b>c){t=b; b=c; c=t;}
		System.out.print(a+" "+b+" "+c);
	}
	
}