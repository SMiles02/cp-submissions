n, t = map(int, input().split());ans=-1
#print(10**(n-1), 10**n)
for i in range(10**(n-1), 10**n):
    if i%t==0:
        ans=i
        break
print(ans)