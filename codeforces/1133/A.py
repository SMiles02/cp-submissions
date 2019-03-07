h1,m1=map(int, input().split(":"))
h2,m2=map(int, input().split(":"))
avgM = ((h1+h2)*60 + m1 + m2)/2
h3 = int(avgM // 60)
m3 = int(avgM % 60)
if h3 < 10:
    h3 = "0" + str(h3)
else:
    h3 = str(h3)
if m3 < 10:
    m3 = "0" + str(m3)
else:
    m3 = str(m3)
print(h3+":"+m3)