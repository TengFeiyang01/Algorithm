import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def numberOfAlerts(precedingMinutes, alertThreshold, numCalls):
    s = ans = 0
    n = len(numCalls)
    for i in range(n):
        s += numCalls[i]
        if i >= precedingMinutes:
            s -= numCalls[i - precedingMinutes]
        if i >= precedingMinutes - 1 and s > precedingMinutes * alertThreshold:
            ans += 1
    return ans

def solve() -> None:
    print(numberOfAlerts(3, 4, [2,2,2,2,5,5,5,8]))
    print(numberOfAlerts(3, 5, [0, 11, 10, 10, 7]))
    print(numberOfAlerts(3, 10, [0, 11, 10, 10, 7]))

if __name__ == '__main__':
    solve()