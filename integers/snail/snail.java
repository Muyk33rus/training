import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int h,a,b,t=0,i=0;
		h=in.nextInt();
		a=in.nextInt();
		b=in.nextInt();
		while(t<=h){
			i++;
			t+=a;
			if(t>=h){
				System.out.print(i);
				break;
			}
			t-=b;
		}
		
	}
	
}