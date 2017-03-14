import java.util.Scanner;
import java.math.*;

import java.util.Scanner;
public class hello {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x1,y1,x2,y2;

        x1=in.nextInt();
        y1=in.nextInt();
        x2=in.nextInt();
        y2=in.nextInt();
        int d_x = x1 - x2;
        int d_y = y1 - y2;
        if (d_x != 0 && d_y != 0) {
            if (d_x == d_y || d_x == -d_y) {
                System.out.print("YES");
            }
            else{
                System.out.print("NO");
                }
        }
        else if(d_x != 0 || d_y != 0){
            System.out.print("YES");
           }
        else{
            System.out.print("NO");
        }
    }
    
}