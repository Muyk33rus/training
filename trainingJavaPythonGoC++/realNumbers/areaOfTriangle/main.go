package main

import "fmt"

func main() {
	var x1,x2,y1,y2 int32;
	fmt.Scanf("%d",&x1)
	fmt.Scanf("%d",&y1)
	fmt.Scanf("%d",&x2)
	fmt.Scanf("%d",&y2)
	if (y1 - y2 == x1 - x2 || y1 - y2 == -(x1 - x2)) {
		fmt.Printf("YES")
	} else{
		fmt.Printf("NO")
	}
	
}