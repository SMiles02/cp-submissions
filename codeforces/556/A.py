n = int(input())
s = list(str(input()))
print(max(s.count("1"), s.count("0")) - min(s.count("1"), s.count("0")))