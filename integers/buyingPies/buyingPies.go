package main
import "fmt"
func main() {
	var a,b,c int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	fmt.Scanf("%d",&c)
	b*=c
	a=c*a+(b/100)
	b=b%100
	fmt.Println(a,b)
}