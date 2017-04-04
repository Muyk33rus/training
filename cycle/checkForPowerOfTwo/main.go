package main

import "fmt"

func main() {
	var n,t int32
	t=1
	fmt.Scanf("%d",&n)
	for(t <= n) {
        if(t==n){
            fmt.Printf("YES")
            break;
        }
        t *= 2
    }
    if (t!=n){
		fmt.Printf("NO")
	}
	
}