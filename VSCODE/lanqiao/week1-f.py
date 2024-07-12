import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
from bisect import bisect_left, bisect_right


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, q = mint()
    a = ints()
    for i in range(q):
        x = sint()
        l, r = bisect_left(a, x), bisect_right(a, x)
        if l == n or a[l] != x:
            print(-1, -1)
        print(l + 1, r)

if __name__ == '__main__':
    solve()