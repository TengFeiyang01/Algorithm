import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

sys.setrecursionlimit(100000)

def solve() -> None:
    n, m = mint()
    pos1 = []
    pos2 = []
    s = [input() for i in range(n)]

    def dfs(i, j, pos):
        pos.add((i, j))
        for x, y in (i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1):
            if 0 <= x < n and 0 <= y < m and (x, y) not in pos:
                dfs(x, y, pos)
    
    for i, r in enumerate(s):
        for j, c in enumerate(r):
            if c == 'X':
                dfs(i, j, pos1 if not pos1 else pos2)

    ans = inf

    for (x, y) in pos1:
        for (a, b) in pos2:
            ans = min(ans, abs(x-a)+abs(y-b))
    print(ans)


if __name__ == '__main__':
    solve()