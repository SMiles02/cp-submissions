n, p = map(int, input().split())
s = list(str(input()))
isPossible = False
for i in range(0, n-p):
    if s[i] == ".":
        if s[i+p] == "1":
            s[i] = "0"
        elif s[i+p] == "0":
            s[i] = "1"
        else:
            s[i] = "1"
            s[i+p] = "0"
        isPossible=True
        break
    elif s[i+p] == ".":
        if s[i] == "1":
            s[i+p] = "0"
        elif s[i] == "0":
            s[i+p] = "1"
        else:
            print("Whoops! Error #1 occured!")
        isPossible=True
        break
    elif s[i] != s[i+p]:
        isPossible=True
        break
if isPossible:
    for j in range(0,n):
        if s[j] == ".":
            s[j] = "0"
    print(''.join(s))
else:
    print("No")
