n, s = map(int, input().split())
times = []
for z in range(0, n):
  h, m = map(int, input().split())
  times.append((h*60)+m)
if times[0] - (s+1) >= 0:
  print("0 0")
else:
  for i in range(0, n):
    if i != n-1:
      if (times[i+1] - times[i]) - 2 >= 2 * s:
        ans = times[i] + 1 + s
        #print(i)
        break
    else:
      ans = times[i] + s + 1
  ansM = ans % 60
  ansH = int((ans - ansM) / 60)
  print(ansH, ansM)