t=-1
x=-1
count=-1
while (x!=0):
	x=int(input())
	if(x>t):
		t=x
		count=1
	elif(t==x):
		count+=1
print(count)