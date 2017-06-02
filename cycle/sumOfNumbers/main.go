package main

import "fmt"

func main() {
	var x,t int32
	t=0
	x=-1
	for(x!=0){
		fmt.Scanf("%d",&x)
			t+=x
	}
	fmt.Print(t)
	
}