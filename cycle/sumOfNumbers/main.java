import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x,t=0;
		while((x=in.nextInt())!=0){
				t+=x;
		}
		System.out.print(t);
	}
}