def oddsFirst(oddNums,evenNums):
    minimum = min(len(oddNums),len(evenNums))
    for i in range(minimum):
        oddNums.remove(oddNums[-1])
        evenNums.remove(evenNums[-1])
    if len(oddNums) > 0:
        oddNums.remove(oddNums[-1])
    return sum(evenNums) + sum(oddNums)
def evensFirst(oddies,evenies):
    minimum = min(len(oddies),len(evenies))
    for i in range(minimum):
        oddies.remove(oddies[-1])
        evenies.remove(evenies[-1])
    if len(evenies) > 0:
        evenies.remove(evenies[-1])
    return sum(evenies) + sum(oddies)
n = int(input())
a = [int(x) for x in input().split()]
odds=[];evens=[]
for i in a:
    if i % 2 == 0:
        evens.append(i)
    else:
        odds.append(i)
odds.sort()
evens.sort()
oddsAns = oddsFirst(odds,evens)
evensAns = evensFirst(odds,evens)
print(min(oddsAns,evensAns))