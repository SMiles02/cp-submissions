n = int(input())
a = [int(x) for x in input().split()]
ans=a[n-1]
for i in range(n-2,-1,-1):
   a[i]=max(min(a[i],a[i+1]-1),0)
   ans+=a[i]
#print(*a)
print(ans)