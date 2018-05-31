n = int(input())
a = [int(x) for x in input().split()]; a.sort()
if n%2==0:
    print(a[int(n/2-1)])
else:
    print(a[int(n/2 -0.5)])