import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x,f_0=0,f_1=1;
		x=in.nextInt();
		while(x>1){
			int temp=f_1;
			f_1+=f_0;
			f_0=temp;
			x--;
		}
		System.out.print(f_1);
	}
}