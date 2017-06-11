package main
import "fmt"
func main() {
	var a,b,c int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	fmt.Scanf("%d",&c)
	a=a+b+c;
	if(a%2==0){
		a/=2
	} else {
		a=a/2+1
	}
	fmt.Println(a)
}