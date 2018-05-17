n = int(input())
k=[[0 for x in range(n)] for y in range(n)]
k[0][0] = 1
for i in range(n):
    for j in range(n):
        if not (i == 0 and j == 0):
            k[i][j] = k[max(0, i-1)][max(0, j)] + k[max(0, i)][max(0, j-1)]
print(k[n-1][n-1])