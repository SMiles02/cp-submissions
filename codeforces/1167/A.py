n = int(input())
for i in range(n):
    k = int(input())
    s = list(str(input()))
    if "8" in s:
        while s[0] != "8":
            s.remove(s[0])
        if len(s) >= 11:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")