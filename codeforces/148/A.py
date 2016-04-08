k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())

def dragonsHurt(k, l, m, n, d):
    count = 0
    for i in range(1, d + 1):
        if i % k == 0:
            count = count + 1
            #print(i)

        elif i % l == 0:
            count = count + 1
            #print(i)

        elif i % m == 0:
            count = count + 1
            #print(i)

        elif i % n == 0:
            count = count + 1
            #print(i)

    return count

print(dragonsHurt(k, l, m, n, d))
