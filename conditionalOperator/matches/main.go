package main

import "fmt"

func main() {
	var a,b,c int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	fmt.Scanf("%d",&c)
	if ((a==b&&b!=c)||(a==c&&a!=b)||(c==b&&c!=a)){
		fmt.Printf("%d",2)
	} else if (a==b&&b==c){
		fmt.Printf("%d",3)
	} else {
		fmt.Printf("%d",0)
	}

}