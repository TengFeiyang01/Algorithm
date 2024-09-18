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
    s = input()
    ans = 0
    stk = []
    for i, c in s:
        if c == '(':
            stk.append(i)
        else:
            if stk:
                stk.pop()
                if len(stk) == 0:
                    ans = max(ans, i + 1)
            

if __name__ == '__main__':
    solve()