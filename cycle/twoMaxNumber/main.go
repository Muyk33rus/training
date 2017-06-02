package main

import "fmt"

func main() {
	var x,max, s_max int32
	max=-1
	s_max=-1
	x=-1
	for(x!=0){
		fmt.Scanf("%d",&x)
		if(max<=x){
			s_max=max
			max=x
		}else if(s_max<x){
			s_max=x
		}
	}
	fmt.Print(s_max)
	
}