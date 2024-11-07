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
    a = [i for i, x in enumerate(a, 1) if x == i]
    ans = len(a)
    i = 1
    while i < len(a):
        if a[i] - a[i - 1] == 1:
            ans -= 1
            i += 1
        i += 1
    print(ans)

if __name__ == '__main__':
    solve()