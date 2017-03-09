v=int(input())
t=int(input())
s=109
s=(s + (v * t % s)) % s
print(s)