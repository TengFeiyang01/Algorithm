import sys

from heapq import heapify, heappop, heappush
from functools import lru_cache
# from typing import Counter
# import math
# import random
input = lambda: sys.stdin.readline()



n,m,k = map(int, input().split())
dp = [[0 for i in range(m+1)]]
for i in range(1, n+1):
    tmp = list(map(int, input().split()))
    dp.append([0] + tmp)
    for j in range(1, m+1):
        dp[i][j] += dp[i][j-1]
ans = 0
for i in range(1, m+1):
    for j in range(i, m+1):
        s = 1
        tmp = 0
        for t in range(1, n+1):
            tmp += dp[t][j]-dp[t][i-1]
            while tmp > k:
                tmp -= dp[s][j]-dp[s][i-1]
                s += 1
            ans += t-s+1
print(ans)
