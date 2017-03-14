import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b,c,d;

		a=in.nextInt();
		b=in.nextInt();
		c=in.nextInt();
		d=in.nextInt();
		if (a == c || b == d){
			System.out.print("YES");
		}
		else
			System.out.print("NO");
	}
	
}