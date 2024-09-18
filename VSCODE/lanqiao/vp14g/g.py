import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = sint()
    a = [0] + ints()
    dp = [[0] * n for _ in range(1 << n)]
    res = 0
    for i in range(n):
        dp[1 << i][i] = 1
    for mask in range(1, 1 << n):
        i = mask.bit_count()
        for last in range(n):
            if ((mask >> last & 1) == 0): continue
            for j in range(n):
                if (mask >> j & 1) == 0 or j == last: continue
                dif = last - j
                if a[i - 1] == 1 and dif != 1: continue
                if a[i - 1] == 0 and dif == 1: continue
                dp[mask][last] += dp[mask & ~(1 << last)][j]
    print(sum(dp[-1]))    
    

if __name__ == '__main__':
    solve()