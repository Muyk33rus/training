import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int i=in.nextInt();
		i++;
		for(int k=1;k<10000;k++){
			if(0==(i%2)){
				System.out.println(i);
				break;
			}
			i+=k;
		}
	}
	
}
