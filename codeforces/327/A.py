n = int(input())
a = [int(x) for x in input().split()]
if n == sum(a):
    print(n-1)
else:
    maxSoFar = 0
    for i in range(n):
        current = 0
        for j in range(n-i):
            if a[i+j] == 0:
                current+=1
            else:
                current-=1
            if current <= 0:
                break
            maxSoFar = max(maxSoFar, current)
    print(maxSoFar + a.count(1))