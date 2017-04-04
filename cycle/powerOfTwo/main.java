import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x,t=1;
		x=in.nextInt();
		while(x>=t){
			System.out.print(t+" ");
			t*=2;
		}
	}
	
}