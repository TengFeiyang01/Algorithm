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
    stk = []
    for x in a:
        stk.append(x)
        while len(stk) >= 2 and stk[-1] == stk[-2]:
            stk.pop()
            stk[-1] += 1
    print(*stk)

if __name__ == '__main__':
    solve()