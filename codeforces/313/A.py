n = int(input())
if n >= 0:
    print(n)
else:
    n = list(str(n))
    if len(n) == 2:
        print(0)
    elif len(n) == 3:
        print(max(int(n[0] + n[2]), int(n[0] + n[1])))
    else:
        last = int(n[-1])
        secLast = int(n[-2])
        if last >= secLast:
            print(''.join(n[:-1]))
        else:
            print("-" + str(''.join(n[1:-2])) + str(n[-1]))