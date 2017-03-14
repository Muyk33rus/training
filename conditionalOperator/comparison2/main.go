package main

import "fmt"

func main() {
	var a,b int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	if (a>b) {
		fmt.Printf("%d",1)
	} else if (b>a) {
		fmt.Printf("%d",2)
	} else {
		fmt.Printf("%d",0)
	}

}