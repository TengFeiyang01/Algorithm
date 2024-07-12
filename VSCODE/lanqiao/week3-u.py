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
    s = input()
    d = defaultdict(int)
    mx = cnt = 0
    for c in s:
        d[c] += 1
        if d[c] > mx:
            cnt = 1
            mx = d[c]
        elif d[c] == mx:
            cnt += 1
    print(pow(mx, n, 1000000007))
    


if __name__ == '__main__':
    solve()