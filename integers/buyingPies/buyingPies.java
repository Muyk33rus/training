import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		int c=in.nextInt();
		int v=a*c;
		int w =b*c;
		v+=w/100;
		w=w%100;
		System.out.print(v+" "+w);
		
	}
	
}