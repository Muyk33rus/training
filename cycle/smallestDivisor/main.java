import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x,y=2;
		x=in.nextInt();
		while(x%y!=0){
			y++;
		}
		System.out.print(y);
	}
	
}