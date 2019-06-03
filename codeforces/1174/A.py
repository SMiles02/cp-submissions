n=int(input())
a=[int(x) for x in input().split()]
isTrue=True;first=a[0]
for z in a:
    if z != first:
        isTrue = False
        break
if isTrue:
    print(-1)
else:
    if sum(a[:n]) == sum(a[n:]):
        end = a[-1]
        for i in range(n):
            if a[i] != end:
                this = a[i]
                a[i] = end
                a[-1] = this
                print(*a)
                break
    else:
        print(*(a[n:]+a[:n]))