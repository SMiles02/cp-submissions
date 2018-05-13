n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]

print(sum(a) - sum(b))
print(sum(b) - sum(c))