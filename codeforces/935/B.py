n = int(input())
s = str(input())
x=0;y=0;ans=0

for i in range(0,n):
    if s[i] == "R":
        x+=1
    else:
        y+=1
    if x == y and i != (n-1):
        if s[i] == s[i+1]:
            ans+=1
print(ans)