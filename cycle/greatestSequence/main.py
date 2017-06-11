x=0
res=0
temp=0
t_count=0
count=0
while(True):
	x=int(input())
	if (x==0):
		break
	if(temp!=x):
		t_count=count;
		temp=x
		count=1
	else:
		count+=1;
	if(res<count):
		res=count
	elif(res<t_count):
		res=t_count

print(res)