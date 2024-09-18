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
    n, m = mint()
    a = [ints() for _ in range(n)]
    for i in range(n // 2 + 1):
        for j in range(m // 2 + 1):
            if i != n // 2 or j != m // 2:
                a[i][j] += a[n - i - 1][m - j - 1]
            mx = 0
            if i: mx = max(mx, a[i - 1][j])
            if j: mx = max(mx, a[i][j - 1]) 
            a[i][j] += mx
        
    print(a[n//2][m//2])  

if __name__ == '__main__':
    solve()