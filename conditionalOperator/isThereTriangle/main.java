import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b,c;

		a=in.nextInt();
		b=in.nextInt();
		c=in.nextInt();
		if ( b + c > a && c + a > b && b + a > c){
			System.out.print("YES");
		}
		else
			System.out.print("NO");
	}
	
}