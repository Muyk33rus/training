x=int(input())
f_0=0
f_1=1
while (x>1):
	temp=f_1
	f_1+=f_0
	f_0=temp
	x-=1
print(f_1)