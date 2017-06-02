x=int(input())
f_0=0
f_1=1
count=1
while (x>f_1):
	temp=f_1
	f_1+=f_0
	f_0=temp
	count+=1
if (x==f_1):	
	print(count)
else:
	print(-1)