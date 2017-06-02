package main

import "fmt"

func main() {
	var x,t,count int32
	t=-1
	x=-1
	count=-1
	for(x!=0){
		fmt.Scanf("%d",&x)
			if(x>t){
				t=x
				count=1
			}else if(t==x){
				count++
			}
	}
	fmt.Print(count)
	
}