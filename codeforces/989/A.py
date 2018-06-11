flowers = list(str(input()))
ans = False
for i in range(1, len(flowers)-1):
    if flowers[i] == "A" and flowers[i-1] == "B" and flowers[i+1] == "C":
        ans = True
        break
    elif flowers[i] == "A" and flowers[i-1] == "C" and flowers[i+1] == "B":
        ans = True
        break
    elif flowers[i] == "B" and flowers[i-1] == "C" and flowers[i+1] == "A":
        ans = True
        break
    elif flowers[i] == "B" and flowers[i-1] == "A" and flowers[i+1] == "C":
        ans = True
        break
    elif flowers[i] == "C" and flowers[i-1] == "A" and flowers[i+1] == "B":
        ans = True
        break
    elif flowers[i] == "C" and flowers[i-1] == "B" and flowers[i+1] == "A":
        ans = True
        break
if ans == True:
    print("Yes")
else:
    print("No")