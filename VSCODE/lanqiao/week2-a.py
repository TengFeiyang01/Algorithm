import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from itertools import accumulate
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, q = mint()
    a = [0] + ints()
    for i in range(1, n + 1):
        a[i] += a[i - 1]
    for i in range(q):
        l, r = mint()
        print(a[r] - a[l - 1])

if __name__ == '__main__':
    solve()