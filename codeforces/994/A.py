n, m = map(int, input().split())
xL = [int(x) for x in input().split()]
yL = [int(x) for x in input().split()]
ansL = []

for i in xL:
   if i in yL:
      ansL.append(i)
print(*ansL)