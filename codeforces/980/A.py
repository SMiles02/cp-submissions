s = str(input())
pearls = s.count("o")
links = s.count("-")

if pearls == 1 or pearls == 0 or links == 0:
  print("YES")
  
elif links % pearls == 0:
  print("YES")

else:
  print("NO")