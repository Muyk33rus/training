import java.util.Scanner;
import java.math.*;

import java.util.Scanner;
public class hello {
	public static int[] sort(int[] a){
		for (int i = 0;i<a.length;i++){
			int min =a[i];
			int imin=i;
			for (int j = i+1;j<a.length;j++){
				if(a[j]<min){
					min =a[j];
					imin =j;
				}
			}
			if(i!= imin ){
				int temp =a[i];
				a[i]=a[imin];
				a[imin]=temp;
			}
		}
		return a;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int c=0;
		boolean f=false,s=false;
		int[] a =new int[3];
		int[] b =new int[3];
		for (int i = 0;i < 3;i++){
			a[i]=in.nextInt();
		}
		for (int i = 0;i < 3;i++) 
			b[i]=in.nextInt();
		a =sort(a);
		b= sort(b);
		for (int i = 0;i < 3;i++){
	        if (a[i] == b[i])c++;
	        else if (a[i] > b[i])f=true;
	        else if (a[i] < b[i])s=true;
	    }
		if (c == 3)
			System.out.print("Boxes are equal");
		else if (!f&&s)
			System.out.print("The first box is smaller than the second one");
		else if (f&&!s)
			System.out.print("The first box is larger than the second one");
		else
			System.out.print("Boxes are incomparable");

	}
	
}