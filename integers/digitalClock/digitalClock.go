package main
import "fmt"
func main() {
	var N int32;
	fmt.Scanf("%d",&N)
	fmt.Printf("%d:%02d:%02d",N/3600%24,N%3600/60,N%60)
}