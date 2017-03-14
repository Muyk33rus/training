import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b;

		a=in.nextInt();
		b=in.nextInt();
		if(a>b){
			System.out.print(a);
		}
		else if(b>a){
			System.out.print(b);
		}
		else
			System.out.print(a);
	}
	
}
