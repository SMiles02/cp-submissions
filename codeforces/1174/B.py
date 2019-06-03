n = int(input())
a = [int(x) for x in input().split()]
odds=False;evens=False
for i in a:
    if i % 2 == 0:
        evens = True
    else:
        odds = True
if evens and odds:
    a.sort()
print(*a)