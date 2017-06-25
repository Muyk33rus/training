package main

import "fmt"
func min(a, b int32) int32 {
		if (a>b){
			return b;
		}else{
			return a;
		}
}


func main() {
	var n,m,x,y,t int32;
	fmt.Scanf("%d",&n)
	fmt.Scanf("%d",&m)
	fmt.Scanf("%d",&x)
	fmt.Scanf("%d",&y)

	if(n<m){t=n; n=m; m=t;}

	fmt.Printf("%d",min(min(m - x, x), min(n- y, y)))
	
}