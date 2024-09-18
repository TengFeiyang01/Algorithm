import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from collections import deque
# from typing import Counter
# import math
# import random

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))



def solve() -> None:
    n, m = mint()
    dp = [0] * (m + 1)
    ndp = [0] * (m + 1)
    for i in range(n):
        v, w, s = mint()
        for r in range(v):
            q = deque()
            for j in range(r, m + 1, v):
                if q and j - q[0] > v * s:
                    q.popleft()
                while q and dp[q[-1]] + (j - q[-1]) // v * w <= dp[j]:
                    q.pop()
                q.append(j)
                ndp[j] = dp[q[0]] + (j - q[0]) // v * w
        dp = ndp.copy()
    print(dp[-1])


if __name__ == '__main__':
    solve()