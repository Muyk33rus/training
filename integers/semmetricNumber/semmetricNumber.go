package main
import "fmt"
func main() {
	var n int32;
	fmt.Scanf("%d",&n);
	fmt.Println((((n / 1000) - (n % 10)) * ((n / 1000) - (n % 10))) + (((n / 100 % 10) - (n / 10 % 10)) * ((n / 100 % 10) - (n / 10 % 10)))+ 1);
}
