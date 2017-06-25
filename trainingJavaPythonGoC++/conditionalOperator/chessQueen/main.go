package main

import "fmt"

func main() {
	var x1,x2,y1,y2,d_x,d_y int32;
	fmt.Scanf("%d",&x1)
	fmt.Scanf("%d",&y1)
	fmt.Scanf("%d",&x2)
	fmt.Scanf("%d",&y2)
 	d_x = x1 - x2;
	d_y = y1 - y2;
    if (d_x != 0 && d_y != 0) {
        if (d_x == d_y || d_x == -d_y) {
            fmt.Printf("YES")
        } else {
            fmt.Printf("NO")
        }
    } else if (d_x != 0 || d_y != 0) {
        fmt.Printf("YES")
    } else {
        fmt.Printf("NO")
    }
	
}