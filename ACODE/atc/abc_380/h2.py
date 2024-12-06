import sys


import heapq
def solve() -> None:
    m = int(input())
    tmp = list(map(int, input().split()))
    n = tmp[0]

    fees = tmp[1:]

    e = [[float('inf')] * n for _ in range(n)]
    k = int(input().strip())

    for _ in range(k):
        x, y, v = map(int, input().strip().split())
        e[x][y] = e[y][x] = min(e[x][y], v)

    dp = [[float('inf')] * (m + 1) for _ in range(n)]
    dp[0][m] = fees[0]
    q = []
    heapq.heappush(q, (-fees[0], m, 0))

    while q:
        f, y, cur = heapq.heappop(q)
        f = -f
        if f > dp[cur][y]:
            continue
        for i in range(n):
            if i == cur:
                continue
            ty = y - e[cur][i]
            tf = f + fees[i]
            if ty <= 0 or tf >= dp[i][ty]:
                continue
            dp[i][ty] = tf
            heapq.heappush(q, (-tf, ty, i))

    ans = min(dp[n-1][0:m+1])
    if ans < 1e7:
        print(ans)
    else:
        print(-1)

if __name__ == '__main__':
    solve()