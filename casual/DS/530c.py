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
    n, m, k = mint()
    a = ints()
    # dp[i][j] 
    """
    for i in range(n):
        pos = -1
        for j in range(i, i-m, -1):
            if a[i] + dp[j][k] > k:
                
                dp[i][j] = max(dp[i][j], a[i] + a[j])
                pos = 
    """
    b = [0] * n
    for i in range(n):
        for j in range(i-1, max(i-m-1, -1), -1):        
            b[i] = max(b[i], a[j])
    
    

if __name__ == '__main__':
    T = sint()
    for __ in range(T):
        solve()