import math
n, k = map(int, input().split())
y = [int(n) for n in input().split()]
z=[]
for i in y:
    if i <= (5-k):
        z.append(i)

print(int(math.floor(len(z) / 3)))