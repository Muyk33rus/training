package main

import "fmt"

func main() {
	var x,f_1,f_0,temp, count int32
	f_0=0
	f_1=1
	count=1
	fmt.Scanf("%d",&x)
	for(x>f_1){
		temp=f_1
		f_1+=f_0
		f_0=temp
		count++
	}
	if(x==f_1){			
		fmt.Print(count)
	}else{
		fmt.Print(-1)
	}
	
}