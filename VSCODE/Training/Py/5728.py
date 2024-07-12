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
    n = sint()
    dp = [0] * (n + 1)
    f = s = -1
    for x in mint():
        if x > f:
            s, f = f, x
            dp[x] -= 1
        elif x > s:
            s = x
            dp[f] += 1
    f = -1
    for i, x in enumerate(dp):
        if x > f:
            s = i
            f = x
    print(s)
        


if __name__ == '__main__':
    solve()