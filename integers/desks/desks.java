import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		int c=in.nextInt();
		int v=(a+b+c)/2;
		if(1==(a+b+c)%2)
			System.out.print(v+1);
		else
			System.out.print(v);
	}
	
}