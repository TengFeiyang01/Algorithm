import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
# from typing import Counter
# import math
# import random
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    l, r = mint()
    def f(x):
        return (x + 1) // 2 + x // 4
    print(f(r) - f(l - 1))

if __name__ == '__main__':
    solve()