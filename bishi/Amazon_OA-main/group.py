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
    a = ints()
    n = len(a)

    a.sort()
    i, j = 0, n-1
    ans = 0
    while i < j:
        if i < j - 1:
            ans += a[j - 1]
            i += 1
            j -= 2
        else:
            break
    return ans

if __name__ == '__main__':
    solve()