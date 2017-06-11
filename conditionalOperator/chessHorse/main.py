x1=int(input())
y1=int(input())
x2=int(input())
y2=int(input())
d_x = x1 - x2;
d_y = y1 - y2;
step_x = (abs(d_x) == 2);
step_y = (abs(d_y) == 2);
side_x = (abs(d_x) == 1);
side_y = (abs(d_y) == 1);
if ((step_x and side_y) or (step_y and side_x)):
	print("YES")
else:
	print("NO")