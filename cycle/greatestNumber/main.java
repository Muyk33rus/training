import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x,t=-1;
		while((x=in.nextInt())!=0){
				if(t<x){
					t=x;
				}
		}
		System.out.print(t);
	}
}