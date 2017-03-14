package main

import "fmt"

func main() {
	var a,b,c int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	fmt.Scanf("%d",&c)
	if ( b + c > a && c + a > b && b + a > c){
		fmt.Printf("YES")
	} else {
		fmt.Printf("NO")
	}

}