import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int prev=-1,cur=-1,next=-1,count=0;
		
		if((prev=in.nextInt())!=0){
			if ((cur=in.nextInt())!=0){
				if((next=in.nextInt())!=0){
					while(next!=0){
						if(prev<cur&&cur>next){
							count++;
						}
						prev=cur;
						cur=next;
						next=in.nextInt();
					}
				}
			}
		}
		System.out.print(count);
	}
}