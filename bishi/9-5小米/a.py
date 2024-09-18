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
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = 10 ** 13
    for x, y in zip(a, b):
        ans = min(ans, x + y)
    suf = b[:]
    for i in range(n - 2, -1, -1):
        suf[i] = min(suf[i + 1], suf[i])
    pre = 10 ** 13
    for i in range(n - 1):
        ans = min(ans, max(min(suf[i + 1], pre), a[i]))
        pre = min(pre, b[i])
    print(ans)
    

if __name__ == '__main__':
    solve()