package main

import "fmt"

func main() {
	var x,f_1,f_0,temp int32
	f_0=0
	f_1=1
	fmt.Scanf("%d",&x)
	for(x>1){
		temp=f_1
		f_1+=f_0
		f_0=temp
		x--
	}			
	fmt.Print(f_1)
	
}