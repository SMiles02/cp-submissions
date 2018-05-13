n = int(input())
s = str(input())
num = 0

while "xxx" in s:
    s = list(s)
    for i in range(0, n-2):
        if s[i] == "x" and s[i+1] == "x" and s[i+2] == "x":
            s = s[0:i+1] + s[i+2:len(s)]
            #print(s)
            s = ''.join(s)
            num += 1
            break
print(num)