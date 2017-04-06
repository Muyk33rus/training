package main

import "fmt"

func main() {
	var prev,cur,count,next int32
	fmt.Scanf("%d",&prev)
	fmt.Scanf("%d",&cur)
	fmt.Scanf("%d",&next)
	count=0
	if(prev!=0){
		if(cur!=0){
			if(next!=0){
				for(next!=0) {
                    if (prev < cur && cur > next) {
                        count++;
                    }
                    prev = cur
                    cur = next
					fmt.Scanf("%d",&next)
                }
            }
        }
    }
	fmt.Print(count)
}