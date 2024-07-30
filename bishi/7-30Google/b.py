import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def solution(heartRate, activityLevel):
    n = len(heartRate)
    ans = 0
    i = 0
    while i < n:
        j = i
        mx, mn = heartRate[i], heartRate[i]
        while j < n and activityLevel[j] == activityLevel[i]:
            mx = max(mx, heartRate[j])
            mn = min(mn, heartRate[j])
            j += 1
        ans = max(ans, mx - mn)
        i = j
    print(ans)

def solve() -> None:
    a = ints()
    b = list(input().split())
    print(solution(a, b))

if __name__ == '__main__':
    solve()