n = int(input())
a = [int(x) for x in input().split()]
ansNum = 0
ansStr = ""
currentIndex = 0

while currentIndex < len(a):
    if a.count(a[currentIndex]) > 1:
        a.remove(a[currentIndex])
    else:
        ansNum+=1
        ansStr += str(a[currentIndex]) + " "
        currentIndex+=1
print(ansNum)
print(ansStr)