import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int prev=-1,cur=-1,next=-1,count=0,t_count=0,max=0;
		if((prev=in.nextInt())!=0){
			if((cur=in.nextInt())!=0){
					while((next=in.nextInt())!=0){
						if(prev<cur&&cur>next){
							if(t_count>count||t_count==0){
								if(max>1)
			                        t_count=count;
							}
							max++;
							count=1;
						} else{
							count++;
						}
						prev=cur;
						cur=next;
					}
			}
		}
		System.out.print(t_count);
	}
}