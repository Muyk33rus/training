import java.util.Scanner;
public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		// System.out.println("Введите количество белочек");
		int N=in.nextInt();
		// System.out.println("Введите количество орешков");
		int K=in.nextInt();
		System.out.println(K%N);
	}

}