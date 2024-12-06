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
    n = int(input())
    a = list(map(int, input().split()))
    odd = sum(x for i, x in enumerate(a) if i % 2 == 1 and x > 0)
    even = sum(x for i, x in enumerate(a) if i % 2 == 0 and x > 0)
    ans = max(odd, even)
    if max(a) < 0:
        ans = max(a)
    print(ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()