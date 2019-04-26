n = int(input())
a = list(str(input()))
f = [int(x) for x in input().split()]
started = False
goodNums = []
for z in range(9):
    if f[z] >= z+1:
        goodNums.append(str(z+1))
mini = n + 0
for y in goodNums:
    if y in a:
        mini = min(mini, a.index(y))
for i in range(mini, n):
    if started:
        if a[i] in goodNums:
            a[i] = str(f[int(a[i])-1])
        else:
            break
    else:
        if a[i] in goodNums and a[i] != str(f[int(a[i])-1]):
            a[i] = str(f[int(a[i])-1])
            started = True
print("".join(a))