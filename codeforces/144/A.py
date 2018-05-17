n = int(input())
a = [int(x) for x in input().split()]
ans=a.index(max(a))
maxi = max(a);a.remove(maxi)
a.insert(0, maxi)
a.reverse()
ans+=a.index(min(a))
print(ans)