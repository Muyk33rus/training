import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b,c;

		a=in.nextInt();
		b=in.nextInt();
		c=in.nextInt();
		if ( b == c  && c == a ){
			System.out.print(3);
		}
		else if(b == c || c == a ){
			System.out.print(2);
		}
		else
			System.out.print(0);
	}
	
}