package main

import "fmt"

func main() {
	var a,b,c int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	fmt.Scanf("%d",&c)
	if (a>b && a>c) {
		fmt.Printf("%d",a)
	} else if (b>a && b>c) {
		fmt.Printf("%d",b)
	} else {
		fmt.Printf("%d",c)
	}

}