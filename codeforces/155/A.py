n = int(input())
pointsInContests = [int(x) for x in input().split()]

def amazingPerformances(n, pointsInContests):
    amazingPerformancesVariable = 0
    for i in range(0, n):
        if i == 0:
            best = pointsInContests[i]
            worst = pointsInContests[i]

        else:
            if pointsInContests[i] > best:
                amazingPerformancesVariable = amazingPerformancesVariable + 1
                best = pointsInContests[i]

            if pointsInContests[i] < worst:
                amazingPerformancesVariable = amazingPerformancesVariable + 1
                worst = pointsInContests[i]

        #print(str(i + 1) + ". Best = " + str(best) + ". Worst = " + str(worst))

    return amazingPerformancesVariable

print(amazingPerformances(n, pointsInContests))

