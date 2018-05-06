n = int(input())
s = str(input())
l = []
for z in range(0, n-1):
  l.append(s[z] + s[z+1])

maxNum = 0
maxStr = ""

for i in l:
  this = l.count(i)
  if this > maxNum:
    maxNum = this
    maxStr = i
print(maxStr)