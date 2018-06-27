n = int(input())
last = []
this = []
for z in range(n):
    t = str(input())
    last.append(t)
for y in range(n):
    u = str(input())
    this.append(u)
xxxs = min(last.count("XXXS"), this.count("XXXS"))
xxs = min(last.count("XXS"), this.count("XXS"))
xs = min(last.count("XS"), this.count("XS"))
s = min(last.count("S"), this.count("S"))
m = min(last.count("M"), this.count("M"))
l = min(last.count("L"), this.count("L"))
xl = min(last.count("XL"), this.count("XL"))
xxl = min(last.count("XXL"), this.count("XXL"))
xxxl = min(last.count("XXXL"), this.count("XXXL"))
"""for a in range(xxxs):
    last.remove("XXXS")
    this.remove("XXXS")
for b in range(xxs):
    last.remove("XXS")
    this.remove("XXS")
for c in range(xs):
    last.remove("XS")
    this.remove("XS")
for d in range(s):
    last.remove("S")
    this.remove("S")
for e in range(m):
    last.remove("M")
    this.remove("M")
for f in range(l):
    last.remove("L")
    this.remove("L")
for g in range(xl):
    last.remove("XL")
    this.remove("XL")
for h in range(xxl):
    last.remove("XXL")
    this.remove("XXL")
for j in range(xxxl):
    last.remove("XXXL")
    this.remove("XXXL")"""
print(n - (xxxs + xxs + xs + s + m + l + xl + xxl + xxxl))
