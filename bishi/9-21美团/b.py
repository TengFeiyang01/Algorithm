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

def solve1():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    mx = [-inf] * (m + 1)
    res = 0
    for i in range(n):
        res += c[i]
        mx[a[i]] = max(mx[a[i]], b[i] - c[i])
    for i in range(m+1):
        res += max(0, mx[i])
    print(res)


def solve() -> None:
    n, m = mint()
    a = ints()
    b = ints()
    c = ints()
    d = defaultdict(int)
    
    for i in range(n):
        if a[i] not in d:
            d[a[i]] = -inf
        d[a[i]] = max(d[a[i]], b[i]-c[i])
    ans = sum(c)
    for v in d.values():
        if v > 0:
            ans += v
    print(ans)
    
    

if __name__ == '__main__':
    solve1()