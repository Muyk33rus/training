t_count=0
count=0
max=0
prev=int(input())
cur=int(input())
next=int(input())
if(prev!=0):
	if(cur!=0):
		if(next!=0):
			while(next!=0):
				if(prev<cur and cur>next):
					if(max>1):
						t_count=count
					count=1
					max+=1
				else:
					count+=1
				prev=cur
				cur=next
				next=int(input())
print(t_count)