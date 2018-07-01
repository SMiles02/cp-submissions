def oddEvenCounter(theList):
    odds = 0; evens = 0
    for z in theList:
        if z % 2 == 0:
            evens+=1
        else:
            odds+=1
    if odds == evens:
        return True
    else:
        return False

n, B = map(int, input().split())
a = [int(x) for x in input().split()]
if n % 2 == 1:
    print(0)
elif not oddEvenCounter(a):
    print(0)
else:
    prices = []
    for i in range(2, n, +2):
        newL = a[i:]
        if len(newL) == 0:
            break
        else:
            if oddEvenCounter(newL):
                prices.append(max(a[i], a[i-1]) - min(a[i], a[i-1]))
    prices.sort()
ans = 0
for j in prices:
    if B - j >= 0:
        B-=j
        ans+=1
    else:
        break
print(ans)