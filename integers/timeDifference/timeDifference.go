package main
import "fmt"
func main() {
	var i int32;
	fmt.Scanf("%d",&i);
	fmt.Println(i/100+i%100/10+i%10);
}