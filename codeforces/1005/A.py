n = int(input())
a = [int(x) for x in input().split()]
ansL = []; thisIsStart = True
for i in range(n):
    if thisIsStart:
        count = 1
        thisIsStart = False
    else:
        count+=1
    if i != n-1:
        if a[i+1] == 1:
            thisIsStart = True
            ansL.append(count)
    else:
        ansL.append(count)
print(a.count(1))
print(*ansL)