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
    N = 3010
    n, m, P = map(int, input().split())
    g = [[0 for _ in range(m + 2)] for _ in range(n + 2)]
    h = [[0 for _ in range(m + 2)] for _ in range(n + 2)]

    stk = []
    l = [0 for i in range(m + 2)]
    r = [0 for i in range(m + 2)]
    def work(h):
        h[0] = -1
        h[m + 1] = -1

        stk.append(0)
        ##单调栈模板
        for i in range(1, m + 1):
            while h[stk[-1]] >= h[i]: stk.pop()
            l[i] = stk[-1]
            stk.append(i)

        stk.append(m + 1)
        for i in range(m, 0, -1):
            while h[stk[-1]] >= h[i]: stk.pop()
            r[i] = stk[-1]
            stk.append(i)

        res = 0
        for i in range(1, m + 1):
            res = max(res, h[i] * (r[i] - l[i] - 1))
        return res

    for _ in range(P):
        x, y = map(int, input().split())
        g[x][y] = 1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if g[i][j] != 1:
                h[i][j] = h[i - 1][j] + 1

    res = 0
    for i in range(1, n + 1):
        res = max(res, work(h[i]))
    print(res)

if __name__ == '__main__':
    solve()
