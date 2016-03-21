n, m = map(int, input().split())

divisors = []

test = 0

while test != n:
    if n - test >= 2:
        test = test + 2
        divisors.append(2)

    elif n - test == 1:
        test = test + 1
        divisors.append(1)

finished = False
stillPossible = True

while finished == False and stillPossible == True:
    if len(divisors) % m == 0:
        print(len(divisors))
        finished = True

    else:
        if divisors[0] == 2:
            divisors.remove(divisors[0])#
            divisors.append(1)
            divisors.append(1)

        else:
            print(-1)
            stillPossible == False
            raise SystemExit(0)
