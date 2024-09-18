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
    n, k = mint()
    a = []
    for i in range(n):
        a.append(ints())

    l, r = 1, 100000
    while l < r:
        mid = l + r + 1 >> 1
        if sum((h // mid) * (w // mid) for h, w in a) >= k:
            l = mid
        else:
            r = mid - 1
    print(r)

if __name__ == '__main__':
    solve()