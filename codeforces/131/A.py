s = str(input())
if s.upper() == s:
    s = s.swapcase()

else:
    isTrue = True
    for i in range(0, len(s)):
        if i == 0:
            if s[0] != s[0].lower():
                isTrue = False
                break
        elif s[i] != s[i].upper():
            isTrue = False
            break
    if isTrue:
        s=s.swapcase()

print(s)