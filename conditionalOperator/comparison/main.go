package main

import "fmt"

func main() {
	var a,b int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	if (a>b) {
		fmt.Printf("%d",a)
	} else if (b>a) {
		fmt.Printf("%d",b)
	} else {
		fmt.Printf("%d",a)
	}

}