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


def solve() -> None:
    n = int(input())
    a = list(map(int, input().split()))


    def dfs(l, r, s):
        nonlocal ans
        ans = max(ans, s)
        if l - 1 >= 0 and a[l - 1] > s:
            dfs(l - 1, r, s + a[l - 1])
        if r + 1 < n and a[r + 1] > s:
            dfs(l, r + 1, s + a[r + 1])
    res = []
    for i in range(n):
        ans = 0
        dfs(i, i, a[i])
        res.append(ans)
    print(*res)

if __name__ == '__main__':
    solve()