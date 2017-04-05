package main

import "fmt"

func main() {
	var x,t int32
	t=-1
	x=-1
	for(x!=0){
		fmt.Scanf("%d",&x)
			if(x>t){
				t=x
			}
	}
	fmt.Print(t)
	
}