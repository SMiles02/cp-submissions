n = int(input())
t = [int(x) for x in input().split()]
amount = min(t.count(1), t.count(2), t.count(3)); print(amount)
l1 = []; l2 = []; l3 = []
for i in range(n):
    if t[i] == 1 and len(l1) < amount:
        l1.append(i+1)
    elif t[i] == 2 and len(l2) < amount:
        l2.append(i+1)
    elif t[i] == 3 and len(l3) < amount:
        l3.append(i+1)
    if len(l1) == len(l2) == len(l3) == amount:
        break
#print(l1, l2, l3)
for j in range(amount):
    print(l1[j], l2[j], l3[j])