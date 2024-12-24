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
    n, m = mint()
    ans = cur = 0
    ok = True
    for i in range(n):
        c = len(input())
        if cur + c <= m and ok:
            cur += c
            ans += 1
        else:
            ok = False
    print(ans)

if __name__ == '__main__':
    for _ in range(int(input())):
        solve()