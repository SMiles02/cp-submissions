n, k = map(int, input().split())
a = [int(x) for x in input().split()]
ans = 0
while len(a) > 0 and k >= a[0]:
    ans+=1
    a.remove(a[0])
while len(a) > 0 and k >= a[len(a)-1]:
    ans+=1
    a = a[:-1]
print(ans)