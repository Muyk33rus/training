package main

import "fmt"

func main() {
	var prev,cur,count,next,t_count,max int32
	fmt.Scanf("%d",&prev)
	fmt.Scanf("%d",&cur)
	fmt.Scanf("%d",&next)
	count=0
	t_count=0
	max=0
	if(prev!=0){
		if(cur!=0){
			if(next!=0){
				for(next!=0) {
                    if (prev < cur && cur > next) {
                        if(max>1){
                        	t_count=count
                        }
                     	count=1
                 		max++
                 	} else{
                    	count++
                 	}
                    prev = cur
                    cur = next
					fmt.Scanf("%d",&next)
                }
            }
        }
    }
	fmt.Print(t_count)
}