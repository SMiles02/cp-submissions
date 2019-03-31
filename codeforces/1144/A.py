n = int(input())
alpha = list("abcdefghijklmnopqrstuvwxyz")
inpL = []
for z in range(n):
    inpL.append(str(input()))
for i in inpL:
    isTrue = True
    started = False
    ended = False
    patternNoError = True
    for letter in range(26):
        if alpha[letter] in i:
            if i.count(alpha[letter]) > 1:
                isTrue = False
                break
            if not started:
                if not ended:
                    started = True
                else:
                    patternNoError = False
                    break
        else:
            if started:
                started = False
                ended = True
    if isTrue and patternNoError:
        print("YES")
    else:
        print("NO")