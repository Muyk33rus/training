import sys

n=int(input())
a=1
sq=a*a
while sq<=n :
	sys.stdout.write(str(sq)+" ")
	a+=1
	sq=a*a