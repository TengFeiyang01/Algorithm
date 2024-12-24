import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

dirs = [
    [(1, 0), (0, 1), (-1, 0), (0, -1)],
    [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)],
 ]


def solve() -> None:
    n, m = mint()
    g = [input() for _ in range(n)]
    dp = [[[inf] * 2 for _ in range(m)] for _ in range(n)]
    dp[0][0][0] = 0
    q = deque()
    q.append((0, 0, 0))
    
    while q:
        x, y, d = q.popleft()
        if g[x][y] == 'S':
            if dp[x][y][d ^ 1] > dp[x][y][d] + 1:
                dp[x][y][d ^ 1] = dp[x][y][d] + 1
                q.append((x, y, d ^ 1))
        
        for dx, dy in dirs[d]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and g[nx][ny] != 'X':
                if dp[nx][ny][d] > dp[x][y][d] + 1:
                    dp[nx][ny][d] = dp[x][y][d] + 1
                    q.append((nx, ny, d))

    if min(dp[n - 1][m - 1]) == inf:
        print(-1)
    else:
        print(min(dp[n - 1][m - 1]))

if __name__ == '__main__':
    solve()