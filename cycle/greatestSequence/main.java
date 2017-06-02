import java.util.Scanner;

public class hello {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x,temp=-1,t_count=0,res=0,count=0;
		
		while((x=in.nextInt())!=0){
			if(temp!=x){
				t_count=count;
				temp=x;
				count=1;
			}else{
				count++;
			}
			if(res<count){
				res=count;
			}else if(res<t_count){
				res=t_count;
			}
		}
		System.out.print(res);
	}
}