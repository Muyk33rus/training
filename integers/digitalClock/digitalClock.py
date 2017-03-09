N=int(input())
print("%d:%02d:%02d" % (N/3600%24,N%3600/60,N%60))