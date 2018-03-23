import math
a, b = map(int, input().split())
print(str(min(a, b)) + " " + str(int(math.floor((a-min(a, b))/2)) + int(math.floor((b-min(a, b))/2))))