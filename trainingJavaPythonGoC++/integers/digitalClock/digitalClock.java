import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N=in.nextInt();
		System.out.format("%d:%02d:%02d",N/3600%24,N%3600/60,N%60);
		
	}
	
}