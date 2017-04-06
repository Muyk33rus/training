count=0
prev=int(input())
cur=int(input())
next=int(input())
if(prev!=0):
	if(cur!=0):
		if(next!=0):
			while(next!=0):
				if(prev<cur and cur>next):
					count+=1
				prev=cur
				cur=next
				next=int(input())
print(count)