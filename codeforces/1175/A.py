for i in range(int(input())):
    n,k=map(int,input().split())
    ans=0
    while n > 0:
        ans+=(n % k)+1
        n//=k
    print(ans-1)