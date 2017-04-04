x=int(input())
t=1
while(x<=t):
	if(t==x):
		print("YES")
		break
	t*=2
if (x!=t):
	print("NO")