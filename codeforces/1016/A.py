import math
n, m = map(int, input().split())
a = [int(x) for x in input().split()]
ansL = []
for i in range(n):
    if i == 0:
        if a[i] < m:
            ansL.append(0)
        elif a[i] % m == 0:
            ansL.append(int(a[i] / m))
        else:
            ansL.append(int(math.floor(a[i] / m)))
        currentRemainder = a[i] % m
    else:
        if a[i] + currentRemainder < m:
            ansL.append(0)
            currentRemainder += a[i]
        elif (a[i] + currentRemainder) % m == 0:
            ansL.append(int((a[i] + currentRemainder) / m))
            currentRemainder = 0
        else:
            ansL.append(int(math.floor((a[i] + currentRemainder) / m)))
            currentRemainder = (a[i] + currentRemainder) % m
print(*ansL)