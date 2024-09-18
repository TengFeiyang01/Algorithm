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
    a = ints()
    m = max(a)
    dp = [1] + [0] * m
    ans = 0
    for x in a:
        if not dp[x]:
            ans += 1
        for j in range(m, x - 1, -1):
            dp[j] += dp[j - x]
    
    print(ans)




if __name__ == '__main__': 
    for _ in range(sint()):
        solve()