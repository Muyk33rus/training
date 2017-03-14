a=[0,0,0]; b=[0,0,0]
for i in range(3):
	a[i]=int(input())
for i in range(3):
	b[i]=int(input())
b.sort()
a.sort()
c=0; f=False; s=False
for i in range(3):
	if (a[i] == b[i]):
		c+=1
	elif (a[i] > b[i]):
		f=True
	elif (a[i] < b[i]):
		s=True
if (c==3):
	print("Boxes are equal")
elif ( False==f and s):
	print("The first box is smaller than the second one")
elif (f and s==False):
	print("The first box is larger than the second one")
else:
	print("Boxes are incomparable")