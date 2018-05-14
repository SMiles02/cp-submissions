shift = str(input())
s = str(input())
keys = list("qwertyuiopasdfghjkl;zxcvbnm,./")
if shift == "L":
    shift = 1
else:
    shift = -1
ans = ""
for i in s:
    j = keys.index(i)
    ans += keys[j+shift]
print(ans)