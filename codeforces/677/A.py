n, h = map(int, input().split())
a = [int(n) for n in input().split()]
ans = 0
for i in a:
    if i > h:
        ans+=2
    else:
        ans+=1
print(ans)