t=int(input())
for abc in range(t):
    n=int(input())
    a=[int(x)for x in input().split()]
    zero=0;one=0;two=0
    for i in range(n):
        if a[i]%3==0:
            zero+=1
        elif a[i]%3==1:
            one+=1
        else:
            two+=1
    mini=min(one,two)
    zero+=mini
    one-=mini
    two-=mini
    zero+=(one//3)
    one=one%3
    zero+=(two//3)
    two=two%3
    print(zero)