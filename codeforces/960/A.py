s = str(input())
aDone = False
bDone = False
nextOK = False
for i in range(0, len(s)):
    if i == len(s) - 1:
        if s[i] == "c":
            nextOK = True
    if not aDone:
        if s[i] == "b":
            aDone = True
        elif s[i] == "c":
            break
    elif aDone and not bDone:
        if s[i] == "a":
            break
        elif s[i] == "c":
            bDone = True
    else:
        if s[i] == "a" or s[i] == "b":
            break

if nextOK:
    if (s.count("c") == s.count("a") or s.count("c") == s.count("b")) and min(s.count("a"), s.count("b"), s.count("c")) > 0:
        print("YES")
    else:
        print("NO")

else:
    print("NO")