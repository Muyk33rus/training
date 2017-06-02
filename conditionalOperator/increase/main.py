a=int(input())
b=int(input())
c=int(input())
if (a>b):
	t=b; b=a; a=t
if (a>c):
	t=c; c=a; a=t
if (b>c):
	t=b; b=c; c=t
print("%d %d %d"%(a,b,c))