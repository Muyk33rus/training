import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b;

		a=in.nextInt();
		b=in.nextInt();
		if(a>b){
			System.out.print(1);
		}
		else if(b>a){
			System.out.print(2);
		}
		else
			System.out.print(0);
	}
	
}