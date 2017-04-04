package main

import "fmt"

func main() {
	var x,y int32
	y=2
	fmt.Scanf("%d",&x)
	for (x % y != 0) {
        y++
    }
	fmt.Print(y)	
}