n = int(input())
ans = 0
while n > 0:
    for i in range(0, 100):
        if 2 * (2 ** i) > n:
            ans+=1
            n -= (2 ** i)
            break
print(ans)