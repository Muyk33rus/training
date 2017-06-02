package main

import "fmt"

func main() {
	var a,b,c,d int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	fmt.Scanf("%d",&c)
	fmt.Scanf("%d",&d)
	if (a==c||b==d) {
		fmt.Printf("YES")
	} else{
		fmt.Printf("NO")
	}
	
}