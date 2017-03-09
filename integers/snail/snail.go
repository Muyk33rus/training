package main
import "fmt"
func main() {
	var h,a,b,t,i int32;
	t=0;
	i=0;
	fmt.Scanf("%d",&h);
	fmt.Scanf("%d",&a);
	fmt.Scanf("%d",&b);
	 for t<=h {
		i++;
		t+=a;
		if(t>=h){
			fmt.Printf("%d", i);
			break;
		}
		t-=b;
	}
}
