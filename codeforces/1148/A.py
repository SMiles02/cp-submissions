a,b,c = map(int, input().split())
c += c + (min(a,b) * 2)
if a != b:
    c+=1
print(c)