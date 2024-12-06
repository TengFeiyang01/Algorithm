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
    s = input()
    n = len(s)
    cnt = [[0] * 10 for _ in range(n + 1)]
    for i, x in enumerate(s, 1):
        x = int(x)
        for j in range(10):
            cnt[i][j] = cnt[i - 1][j]
        cnt[i][x] += 1
    
    
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n+1):
        dp[i][1] = 1
    
    for i, x in enumerate(s, 1):
        for j in range(i, 1, -1):
            for p in range(j - 1, 0, -1):
                ok = j == 1
                for q in range(10):
                    if cnt[i][q] - cnt[j - 1][q] == cnt[j - 1][q] - cnt[p - 1][q] and cnt[i][q] - cnt[j - 1][q] > 0:
                        ok = True
                if ok:
                    dp[i][j] = max(dp[j - 1][p] + 1, dp[i][j])
    ans = 0
    print(max(dp[-1]))        


if __name__ == '__main__':
    solve()