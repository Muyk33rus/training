package first_project;

import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n,sq, a=1;
		sq=a*a;
		n=in.nextInt();
		while(sq<=n){
			System.out.print(sq+" ");
			a++;
			sq=a*a;
		}
	}
	
}