n, k = map(int, input().split())

"""listOfNumbers = []

for i in range(1, n + 1, 2):
    if i % 2 == 1:
        listOfNumbers.append(i)

if len(listOfNumbers) >= k:
    print(listOfNumbers[k - 1])

else:
    for x in range(2, n + 1, 2):
        if x % 2 == 0:
            listOfNumbers.append(x)

    #print(listOfNumbers)

    print(listOfNumbers[k - 1])"""

if n%2==0:
    if k <= n/2:
        print(k*2-1)
    else:
        print(int((k - n/2) * 2))
else:
    if k <= (n/2+0.5):
        print(k*2-1)
    else:
        print(int((k - (n/2+0.5)) * 2))