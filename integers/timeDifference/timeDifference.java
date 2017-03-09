import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tim;
		int ch1=in.nextInt();
		int mi1=in.nextInt();
		int sec1=in.nextInt();
		int ch2=in.nextInt();
		int mi2=in.nextInt();
		int sec2=in.nextInt();
		tim=(ch2-ch1)*3600+(mi2-mi1)*60+(sec2-sec1);
		System.out.print(tim);
		
	}
	
}