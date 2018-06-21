n = int(input())
s = list(str(input()))
for i in range(n):
    if n % (i+1) == 0:
        s = list(''.join(reversed(''.join(s[:i+1])))) + s[i+1:]
print(''.join(s))