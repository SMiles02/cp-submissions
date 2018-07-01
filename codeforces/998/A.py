n = int(input())
a = [int(x) for x in input().split()]

if n <= 1:
    print(-1)
elif n == 2:
    if a[0] == a[1]:
        print(-1)
    else:
        print(1)
        print(1)
elif sum(a) % 2 == 1:
    print(1)
    print(1)
else:
    for i in range(n):
        if sum(a) - a[i] != sum(a) / 2:
            print(1)
            print(i+1)
            break