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
    n = sint()
    a = ints()
    a.sort()
    need = n // 2 + 1
    a = a[:need]
    m = sint()
    b = ints()
    b.sort()
    i, j = need-1, m - 1
    cnt = ans = 0
    
    while i >= 0:
        if j >= 0 and b[j] > a[i]:
            j -= 1
            i -= 1
        else:
            ans += a[i] + 1
            i -= 1
            cnt += 1
    
    if cnt < n - m:
        ans +=  n - m - cnt
    if cnt > n - m:
        ans = -1
    print(ans)

if __name__ == '__main__':
    solve()