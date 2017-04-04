package main

import "fmt"

func main() {
	var n,t int32;
	t=1
	fmt.Scanf("%d",&n)
	for(t <= n) {
   	fmt.Printf("%d ",t)
    t *= 2
    }
}