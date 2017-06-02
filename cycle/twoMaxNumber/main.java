import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x,max=-1,s_max=-1;
		while((x=in.nextInt())!=0){
			if (max<=x){
				s_max=max;
				max=x;
			}else if(s_max<x){
				s_max=x;
			}
		}
		System.out.print(s_max);
	}
}