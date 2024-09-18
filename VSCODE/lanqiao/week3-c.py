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
    n, q = mint()
    a = ints()
    for i in range(n - 1, 0, -1):
        a[i] -= a[i - 1]

    for i in range(q):
        l, r, v = mint()
        a[l - 1] += v
        if r < n:
            a[r] -= v
    for i in range(n):
        if i: a[i] += a[i - 1]
    print(*a)

if __name__ == '__main__':
    solve()