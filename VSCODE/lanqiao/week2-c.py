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


def solve() -> None:
    n, m, q = mint()
    a = [[0] * (m + 1)]
    for i in range(n):
        a.append([0]+ints())
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]
    for i in range(q):
        x1, y1, x2, y2 = mint()
        print(a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1])


if __name__ == '__main__':
    solve()