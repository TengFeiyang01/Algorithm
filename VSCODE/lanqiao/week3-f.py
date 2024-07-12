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
    b = a[:]
    c = [0] * (n + 2)
    for i in range(1, n + 1):
        b[i] += b[i - 1]
    ans = 0
    q = sint()
    for i in range(q):
        l, r = mint()
        ans -= b[r] - b[l - 1]
        c[l] += 1
        c[r + 1] -= 1
    a = a[1:]
    a.sort()
    for i in range(1, n + 1):
        c[i] += c[i - 1]
    c = c[1:n+1]
    c.sort()
    for x, y in zip(a, c):
        ans += x * y
    print(ans)    

if __name__ == '__main__':
    solve()