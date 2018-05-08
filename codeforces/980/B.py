n, k = map(int, input().split())

if k > (2 * (n-1)):
  print("NO")
  
elif k % 2 == 0:
  a1 = "." * n
  a4 = "." * n
  a2 = "." + "#" * int(k/2) + "." * int((n - k/2)-1)
  a3 = "." + "#" * int(k/2) + "." * int((n - k/2)-1)
  
  print("YES")
  print(a1)
  print(a2)
  print(a3)
  print(a4)

elif k <= n-2:
  a1 = "." * n
  a4 = "." * n
  a2 = "." * int((n-k)/2) + "#" * k + "." * int((n-k)/2)
  a3 = "." * n
  
  print("YES")
  print(a1)
  print(a2)
  print(a3)
  print(a4)
  
elif k == n - 1:
  print("NO")

else:
  a1 = "." * n
  a4 = "." * n
  a2 = "." + "#" * int(min(n-2, k)) + "." * ((n-1) - min(n-2, k))
  a3 = "." + "#" + "#" * (k - (a2.count("#") + 2)) + "." * (2 * (n-2) - k) + "#" +"."
  
  print("YES")
  print(a1)
  print(a2)
  print(a3)
  print(a4)