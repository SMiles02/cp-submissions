a, b = map(int, input().split());ans=1; isTrue=True
while isTrue:
    a*=3
    b*=2
    if a > b:
        isTrue=False
        break
    ans+=1
print(ans)