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
    n, t = mint()
    cnt = defaultdict(int)
    res = ans = 0
    for x in ints():
        ans += cnt[t - x]
        if x * 2 == t:
            res += 1
        cnt[x] += 1
    print(res + ans * 2)

if __name__ == '__main__':
    solve()