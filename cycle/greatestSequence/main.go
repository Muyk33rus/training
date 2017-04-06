package main

import "fmt"

func main() {
	var x,count,t_count,temp,res int32
	x=-1
	count=-1
	res=0
	t_count=-1
	temp=0
	for(true){
		fmt.Scanf("%d",&x)
		if(x==0){
			break
		}
		if(temp!=x){
			t_count=count
			temp=x
			count=1
		}else{
			count++
		}
		if(res<count){
			res=count
		}else if(res<t_count){
			res=t_count
		}
	}
	fmt.Print(res)
	
}