import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
from collections import defaultdict


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, m = mint()
    cnt = [0] + ints()
    a = [ints() for i in range(m)]
    def check(x):
        b = [0] * (n + 2)
        for i in range(x):
            c, L, R = a[i]
            b[L] += c
            b[R + 1] -= c
        for i in range(1, n + 1):
            b[i] += b[i - 1]
            if b[i] > cnt[i]:
                return False
        return True


    l, r = 0, m
    while l < r:
        mid = l + r + 1 >> 1
        if check(mid):
            l = mid
        else:
            r = mid - 1
    
    if r == m:
        print(0)
    else:
        print(-1)
        print(r + 1)
    



if __name__ == '__main__':
    solve()