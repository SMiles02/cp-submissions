n, m = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
"""currentRoom = 0
currentGone = 0
for i in range(0, n):
    currentRoom += a[i]
    while len(b) > 0 and b[0] <= currentRoom:
        print(str(i+1) + " " + str(b[0] - currentGone))
        b.remove(b[0])
    currentGone = 0 + currentRoom"""
currentDorm=0
currentRoom=0
for i in range(m):
    while b[i]-currentRoom>a[currentDorm]:
        currentRoom+=a[currentDorm]
        currentDorm+=1
    print(currentDorm + 1, b[i] - currentRoom)








