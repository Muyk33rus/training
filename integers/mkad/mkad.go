package main
import "fmt"
func main() {
	var t,v,s int32;
	fmt.Scanf("%d",&v);
	fmt.Scanf("%d",&t);
	s=109;
	s=(s + (v * t % s)) % s;
fmt.Printf("%d",s)
}
