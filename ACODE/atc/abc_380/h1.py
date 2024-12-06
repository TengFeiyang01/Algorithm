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
    ans = 0
    a.sort()
    stk = []

    for x in a: 
        for j in range(len(stk)):
            if x >= stk[j]:
                stk[j] += 1
                break
        else:
            stk.append(1)

    print(len(stk))
    


if __name__ == '__main__':
    solve()