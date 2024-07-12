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
    s = input()
    n = len(s)
    cnt = [0] * 10
    dp = [[0] * n for _ in range(n)]
    for x in range(2, n + 1):
        for l in range(n - x + 1):
            r = l + x - 1
            if s[l] == s[r]:
                dp[l][r] = dp[l + 1][r - 1]
            elif s[l] > s[r]:
                dp[l][r] = 1
    print(sum(sum(x) for x in dp))
    

if __name__ == '__main__':
    solve()