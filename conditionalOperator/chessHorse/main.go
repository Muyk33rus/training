package main

import "fmt"
import "math"

func main() {
	var x1,x2,y1,y2,d_x,d_y int32;
	var step_x,step_y,side_x,side_y bool
	fmt.Scanf("%d",&x1)
	fmt.Scanf("%d",&y1)
	fmt.Scanf("%d",&x2)
	fmt.Scanf("%d",&y2)
	d_x = x1 - x2;
	d_y = y1 - y2;
	step_x = (math.Abs(float64(d_x)) == 2);
	step_y = (math.Abs(float64(d_y)) == 2);
	side_x = (math.Abs(float64(d_x)) == 1);
	side_y = (math.Abs(float64(d_y)) == 1);
	if ((step_x && side_y) || (step_y && side_x)) {
		fmt.Printf("YES")
	} else{
		fmt.Printf("NO")
	}
	
}