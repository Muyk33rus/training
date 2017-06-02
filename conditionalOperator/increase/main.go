package main

import "fmt"

func main() {
	var a,b,c,t int32;
	fmt.Scanf("%d",&a)
	fmt.Scanf("%d",&b)
	fmt.Scanf("%d",&c)
	if(a>b){t=a; a=b; b=t;}
	if(a>c){t=a; a=c; c=t;}
	if(b>c){t=b; b=c; c=t;}
	fmt.Printf("%d %d %d",a,b,c)
	
}