n = int(input())

while n > 0:
    word = str(input())
    wordList = list(word)

    if len(wordList) <= 10:
        print(word)

    else:
        print(wordList[0] + str(len(wordList) - 2) + wordList[len(wordList) - 1])

    n = n - 1
