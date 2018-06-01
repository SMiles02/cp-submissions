n = int(input()); inpL = []; ordList = [];isTrue = True
for z in range(n):
    inpL.append(str(input()))
inpL.sort(reverse=True,key=len)
#print(inpL)
ordList.append(inpL[0]); inpL.remove(inpL[0])
while len(inpL) > 0:
    this = inpL[0]; inpL.remove(this);ordList.append(this)
    for i in ordList:
        if this not in i:
            isTrue=False
            break
    if isTrue==False:
        break
if isTrue:
    print("YES")
    ordList.reverse()
    for j in ordList:
        print(j)
else:
    print("NO")