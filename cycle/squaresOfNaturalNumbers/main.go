package main

import "fmt"

func main() {
	var n,a,sq int32;
	a=1
	fmt.Scanf("%d",&n)
	sq=a*a
	for(sq<=n){
		fmt.Printf("%d ",sq)
		a++
		sq=a*a
		}
	
}