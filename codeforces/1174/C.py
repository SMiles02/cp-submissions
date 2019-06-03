n=int(input())
currentNum = 1
array = [0]*(n-1)
for i in range(2, n+1):
    if array[i-2] == 0:
        for j in range(1,(n//i)+1):
            if array[(i*j)-2] == 0:
                array[(i*j)-2] = currentNum
        currentNum+=1
print(*array)