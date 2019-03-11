n,k=map(int,input().split())
if k == n or k == 1:
    print(3*n)
elif k <= (n/2):
    print(4*k+3*(n-k)-1)
else:
    k = n+1-k
    print(4*k+3*(n-k)-1)