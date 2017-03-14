package main

import "fmt"

func sort( x [3]int32) [3]int32 {
	for i:= 0;i<len(x);i++{
		var min,imin,temp int32
			min =x[i];
			imin=int32(i);
			for j:= i+1;j<len(x);j++{
				if(x[j]<min){
					min =x[j];
					imin =int32(j);
				}
			}
			if(int32(i)!= imin ){
				temp =x[i];
				x[i]=x[imin];
				x[imin]=temp;
			}
		}
	return x
}

func main() {
	var a [3]int32
	var b [3]int32
	var c int32
	var f,s bool
	f=false
	s=false 
	for i:=0;i<3;i++ {	
		fmt.Scanf("%d",&a[i])
	}
	for i:=0;i<3;i++{
		fmt.Scanf("%d",&b[i])
	}
	a =sort(a)
	b =sort(b)
	for i:= 0;i < 3;i++ {
        if (a[i] == b[i]){
        	c++
    	} else if (a[i] > b[i]){
    		f=true
    	} else if (a[i] < b[i]){
    		s=true
    	}
    }
	if (c == 3){
        fmt.Printf("Boxes are equal")
	} else if (!f&&s){
        fmt.Printf("The first box is smaller than the second one")
	} else if (f&&!s){
        fmt.Printf("The first box is larger than the second one")
	} else{
        fmt.Printf("Boxes are incomparable")
	}
}