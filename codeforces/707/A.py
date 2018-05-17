n, m = map(int, input().split())
inpL = []
for i in range(n):
    x = list(str(input()))
    inpL += x
if "C" in inpL or "M" in inpL or "Y" in inpL:
    print("#Color")
else:
    print("#Black&White")