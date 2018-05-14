n, t = map(int, input().split())
s = list(str(input()))
for j in range(t):
    wasDone = False
    for i in range(n):
        if i != n-1:
            if wasDone:
                wasDone = False
            else:
                if s[i] == "B" and s[i+1] == "G":
                    s[i] = "G"
                    s[i+1] = "B"
                    wasDone = True
print(''.join(s))