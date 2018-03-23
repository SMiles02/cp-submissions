def this(l, r, a):
    ans = 0
    while True:
        if l == 0:
            if a == 0:
                return ans
            else:
                a-=1
        else:
            l-=1

        if r == 0:
            if a == 0:
                return ans
            else:
                a-=1
        else:
            r-=1

        ans+=2

l, r, a = map(int, input().split())

print(this(l, r, a))