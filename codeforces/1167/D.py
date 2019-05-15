n = int(input())
s = list(str(input()))
ans = "";r=0;b=0
for i in s:
    if i == "(":
        if r <= b:
            r+=1
            ans+="0"
        else:
            b+=1
            ans+="1"
    else:
        if r >= b:
            r-=1
            ans+="0"
        else:
            b-=1
            ans+="1"
print(ans)