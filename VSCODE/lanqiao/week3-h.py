import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = sint()
    a = ints()
    cnt = defaultdict(int)
    ans = l = 0
    for r, x in enumerate(a):
        cnt[x] += 1
        while cnt[x] > 1:
            cnt[a[l]] -= 1
            l += 1
        ans = max(ans, r - l + 1)
    print(ans)

if __name__ == '__main__':
    solve()