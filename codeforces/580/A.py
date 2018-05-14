n = int(input())
a = [int(x) for x in input().split()]
longestSubsequence = 0
currentLongest = 0
currentNumber = 0
for i in range(n):
    if a[i] >= currentNumber:
        currentLongest+=1
        longestSubsequence = max(currentLongest, longestSubsequence)
    else:
        currentLongest = 1
    currentNumber = a[i]
print(longestSubsequence)