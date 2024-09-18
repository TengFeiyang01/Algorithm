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
    n = sint()
    a = ints()
    k = sint()
    a.sort()
    p = n - k + 1
    ans = sum(a[n-k+1:n]) + (a[p // 2] if p % 2 else round((a[(p - 1)//2] + a[p // 2]) / 2))
    print(ans)

if __name__ == '__main__':
    solve()