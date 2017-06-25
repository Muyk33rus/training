import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int s = 109;
		int v=in.nextInt();
		int t=in.nextInt();
		s=(s + (v * t % s)) % s;
		System.out.print(s);
		
	}
	
}