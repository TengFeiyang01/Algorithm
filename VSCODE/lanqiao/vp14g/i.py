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
    n, p, q = mint()
    p -= 1
    q -= 1
    a = ints()
    h = []
    mx = max(a[p:q+1])
    mn = min(a[p:q+1])
    for i in range(p, q+1):
        heappush(h, -a[i])
    ans = mx - mn
    for i in range(q + 1, n):
        mn = min(mn, a[i])
        heappush(h, -a[i])
        heappop(h)
        mx = -h[0]
        ans = max(ans, mx - mn)
    h = []
    
    for i in range(p, q+1):
        heappush(h, a[i])
        
    mx = max(a[p:q+1])
    mn = min(a[p:q+1])
    for i in range(p-1, -1, -1):
        mx = max(mx, a[i])
        heappush(h, a[i])
        heappop(h)
        mn = h[0]
        ans = max(ans, mx - mn)
    print(ans)        
        

if __name__ == '__main__':
    solve()