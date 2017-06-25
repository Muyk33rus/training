i =int(input())
i+=1
for k in range(10000):
	if i%2==0:
		print(i)
		break
	i+=k
