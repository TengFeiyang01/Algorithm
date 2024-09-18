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
    n = sint()
    a = [ints() for _ in range(n)]
    # 最大
    l, r = 1, 10000000000
    while l < r:
        ok = True
        mid = l + r >> 1
        for x, y in a:
            if x // mid > y:
                ok = False
        if not ok:
            l = mid + 1
        else:
            r = mid
    print(l, end=' ')
    l, r = 1, 1000000000
    while l < r:
        ok = True
        mid = l + 1 + r >> 1
        for x, y in a:
            if x // mid < y:
                ok = False
        if not ok:
            r = mid - 1
        else:
            l = mid
    print(l)


if __name__ == '__main__':
    solve()