n=int(input())
m=int(input())
x=int(input())
y=int(input())
if(n<m):
	t=n; n=m; m=t;
print("%d"%min(min(m - x, x), min(n- y, y)))