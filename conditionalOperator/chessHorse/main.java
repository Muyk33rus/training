import java.util.Scanner;
import java.math.*;

import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x1,y1,x2,y2;

		x1=in.nextInt();
		y1=in.nextInt();
		x2=in.nextInt();
		y2=in.nextInt();
		int d_x = x1 - x2;
		int d_y = y1 - y2;
		boolean  step_x = (Math.abs(d_x) == 2);
		boolean  step_y = (Math.abs(d_y) == 2);
		boolean  side_x = (Math.abs(d_x) == 1);
		boolean  side_y = (Math.abs(d_y) == 1);
		if ((step_x && side_y) || (step_y && side_x)) {
			System.out.print("YES");
		} else{
			System.out.print("NO");
		}
	}
	
}