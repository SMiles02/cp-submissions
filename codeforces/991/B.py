n = int(input())
a = [float(x) for x in input().split()]
ans = 0
while sum(a) / n < 4.5:
    #print(sum(a) / n)
    a.remove(min(a))
    a.append(5)
    ans+=1
print(ans)