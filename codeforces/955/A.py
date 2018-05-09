import math

hh, mm = map(float, input().split())
H, D, C, N = map(float, input().split())
mm += hh*60

if mm >= 1200:
    print((math.ceil(H / N)) * C * 0.8)
else:
    print(min((math.ceil(H / N) * C), (math.ceil((H + D * (1200 - mm)) / N) * C * 0.8)))