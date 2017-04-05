s_max=-1
max=-1
x=-1
while (x!=0):
	x=int(input())
	if(max>x):
		s_max=max
		max=x	
	elif(s_max<x):
		s_max=x
print(s_max)