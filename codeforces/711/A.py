n = int(input())
inpL = []
for z in range(n):
    inpL.append(list(str(input())))
ans = "NO"
for i in range(n):
    for j in range(4):
        if inpL[i][j] == inpL[i][j+1] == "O":
            inpL[i][j] = "+"
            inpL[i][j+1] = "+"
            ans = "YES"
            break
    if ans == "YES":
        break
if ans == "NO":
    print("NO")
else:
    print("YES")
    for a in inpL:
        print(''.join(a))