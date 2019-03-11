n=int(input())
inpL=[]
for z in range(n):
    inpL.append([int(x)for x in input().split()])
k=int(input())
for i in range(n):
    if inpL[i][0] <= k <= inpL[i][1]:
        print(n-i)
        break