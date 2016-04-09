digOne = str(input())
digTwo = str(input())

def thisThing(digOne, digTwo):
    ans = []
    listDigOne = list(digOne)
    listDigTwo = list(digTwo)

    for i in range(0, len(listDigOne)):
        if listDigOne[i] != listDigTwo[i]:
            ans.append("1")

        else:
            ans.append("0")

    print(''.join(ans))

thisThing(digOne, digTwo)