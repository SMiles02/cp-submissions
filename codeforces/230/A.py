s, n = map(int, input().split())
inpL = []
for z in range(n):
    xY = [int(x) for x in input().split()]
    inpL.append(xY)
isTrue = True
while isTrue:
    var1 = len(inpL)
    for i in inpL:
        #print(i[0])
        if i[0] < s:
            s+=i[1]
            inpL.remove(i)
    var2 = len(inpL)
    if var1 == var2:
        isTrue = False
if len(inpL) == 0:
    print("YES")
else:
    print("NO")