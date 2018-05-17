k, r = map(int, input().split())
if k % 10 == 0:
    print(1)
else:
    for i in range(1, 11):
        if ((i * k) - r) % 10 == 0:
            print(i)
            break
        elif (i*k) % 10 == 0:
            print(i)
            break