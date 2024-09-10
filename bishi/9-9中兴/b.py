import sys
import itertools
from functools import lru_cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

from heapq import heapify, heappop, heappush

def solve() -> None:
    m = int(input())
    p = list(map(int, input().split()))
    n = len(p)
    h = [(x, i) for i, x in enumerate(p)]
    heapify(h)
    ans = []
    while h[0][0] <= m:
        x, i = heappop(h)
        ans.append(p[i])
        if x > m:
            break
        heappush(h, (x+p[i], i))
    print(*ans)

if __name__ == '__main__':
    solve()