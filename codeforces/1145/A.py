n = float(input())
a = [int(x) for x in input().split()]
done = False
while not done:
    for i in range(0,len(a), int(n)):
        k=a[i:i+int(n)]
        k2=k+[]
        k.sort()
        if k == k2:
            print(int(n))
            done = True
            break
    n/=2