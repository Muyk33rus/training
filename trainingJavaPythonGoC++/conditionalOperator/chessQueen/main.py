x1=int(input())
y1=int(input())
x2=int(input())
y2=int(input())
d_x=x1-x2
d_y=y1-y2
if (d_x!=0 and d_y!=0):
	if (d_x==d_y or d_x==-d_y):
		print("YES")
	else:
		print("NO")
elif(d_x!=0 or d_y!=0):
	print("YES")
else:
	print("NO")
