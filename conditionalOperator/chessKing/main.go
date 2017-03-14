package main

import "fmt"

func main() {
	var x1,x2,y1,y2 int32;
	fmt.Scanf("%d",&x1)
	fmt.Scanf("%d",&y1)
	fmt.Scanf("%d",&x2)
	fmt.Scanf("%d",&y2)
	if ((x1 - x2 <= 1 && x1 - x2 >= -1) && (y1 - y2 <= 1 && y1 - y2 >= -1)){
		fmt.Printf("YES")
	} else{
		fmt.Printf("NO")
	}
	
}