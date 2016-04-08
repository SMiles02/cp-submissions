n = int(input())
numbers = [int(x) for x in input().split()]

def oddNumberOut(n, numbers):
    oddNum = []
    evenNum = []

    for i in range(0, n):
        if numbers[i] % 2 == 0:
            evenNum.append(numbers[i])

        elif numbers[i] % 2 == 1:
            oddNum.append(numbers[i])

        if len(oddNum) > 1 and len(evenNum) == 1:
            break

        elif len(evenNum) > 1 and len(oddNum) == 1:
            break



    if len(oddNum) == 1:
        olp = oddNum[0]

    elif len(evenNum) == 1:
        olp = evenNum[0]

    for i in range(0, n):
        if numbers[i] == olp:
            print(i + 1)

oddNumberOut(n, numbers)