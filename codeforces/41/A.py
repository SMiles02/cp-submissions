s = str(input())
t = str(input())

if s == ''.join(reversed(t)):
    print("YES")

else:
    print("NO")