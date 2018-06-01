n, k = map(int, input().split())
a = [int(x) for x in input().split()]
ans = 0; secList = []
for i in range(1,101):
    if a.count(i) > 0:
        ans+=1
        secList.append(i)
if ans >= k:
    print("YES")
    ansStr = ""
    for i in secList[:k]:
        ansStr+=str(a.index(i) + 1)+" "
    print(ansStr)
else:
    print("NO")