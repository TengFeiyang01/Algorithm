import sys
import heapq
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def solve():
    def minPushBox(grid) -> int:
        m, n = len(grid), len(grid[0])
        def check(xx: int, yy: int) -> bool:
            return 0 <= xx < m and 0 <= yy < n

        for i, row in enumerate(grid):
            for j, c in enumerate(row):
                if c == "X":
                    si, sj = i, j
                    grid[i][j] = '0'
                elif c == "B":
                    grid[i][j] = '0'
                    bi, bj = i, j
                elif c == 'G':
                    ei, ej = i, j
                    grid[i][j] = '0'

        dirs = (-1, 0, 1, 0, -1)
        q = deque([(bi, bj, si, sj)])
        vis = [[[[-1] * n for _ in range(m)] for __ in range(n)] for ___ in range(m)]
        vis[bi][bj][si][sj] = 0
        while q:
            cbx, cby, cmx, cmy = q.popleft()
            for i in range(4):
                a, b = dirs[i], dirs[i + 1]
                nx, ny = cmx + a, cmy + b
                if check(nx, ny):
                    if nx == cbx and ny == cby:
                        bx, by = cbx + a, cby + b
                        if check(bx, by) and grid[bx][by] == '0' and vis[bx][by][nx][ny] == -1:
                                q.append((bx, by, nx, ny))
                                vis[bx][by][nx][ny] = vis[cbx][cby][cmx][cmy] + 1
                                if bx == ei and by == ej:
                                    return vis[bx][by][nx][ny]
                    else:
                        if grid[nx][ny] == '0' and vis[cbx][cby][nx][ny] == -1:
                            q.appendleft((cbx, cby, nx, ny))
                            vis[cbx][cby][nx][ny] = vis[cbx][cby][cmx][cmy]
        return -1
    m = int(input())
    g = [input().split() for _ in range(m)]
    print(minPushBox(g))

if __name__ == '__main__':
    solve()