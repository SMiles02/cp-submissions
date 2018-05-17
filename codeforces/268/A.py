n = int(input())
inpL = []; ans = 0
for z in range(n):
    z = [int(x) for x in input().split()]
    inpL.append(z)
for i in inpL:
    for j in inpL:
        if i[0] == j[1]:
            ans+=1
print(ans)