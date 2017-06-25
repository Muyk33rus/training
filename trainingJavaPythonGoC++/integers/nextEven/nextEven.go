package main
import "fmt"
func main() {
	var i int32;
	fmt.Scanf("%d",&i);
	i++;
	for ;i<10000;i++ {
		if (i%2==0){
		fmt.Println(i);
		break;
		}
	}
}