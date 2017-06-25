import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x1,y1,x2,y2;

		x1=in.nextInt();
		y1=in.nextInt();
		x2=in.nextInt();
		y2=in.nextInt();
		if (y1 - y2 == x1 - x2 || y1 - y2 == -(x1 - x2)) {
			System.out.print("YES");
		}
		else
			System.out.print("NO");
	}
	
}