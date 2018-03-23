n = int(input())
a = [int(n) for n in input().split()]
b = 0
c = 0

for i in a:
    if i >= 0:
        b += i

    else:
        c += i

print(b-c)