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
    a = list(map(int, input().split()))
    dp = 1
    a = [1, 2, 4]
    for x in a:
        dp = (dp << x) | dp
    s = sum(a)
    ans = inf
    for i in range(1, s + 1):
        if dp & (1 << i):
            ans = min(ans, max(2 * i, s - i))
    print(ans)



if __name__ == '__main__':
    solve()