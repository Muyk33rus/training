package first_project;

import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		System.out.print((((n / 1000) - (n % 10)) * ((n / 1000) - (n % 10))) + (((n / 100 % 10) - (n / 10 % 10)) * ((n / 100 % 10) - (n / 10 % 10)))+ 1);
		
	}
	
}
