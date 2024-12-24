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
    n, m = mint()
    a = ints()
    lg = int(log2(n))
    for i in range(n-1, 0, -1):
        a[i] -= a[i - 1]
    st = [[0] * (lg + 1) for _ in range(n)]
    for i in range(n):
        st[i][0] = a[i]
    for j in range(1, lg + 1):
        for i in range(n - (1 << j) + 1):
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1])
    def query(l, r):
        k = int(log2(r - l + 1))
        return gcd(st[l][k], st[r - (1 << k) + 1][k])
    ans = []
    for i in range(m):
        l, r = mint()
        if l == r:
            ans.append(0)
        else:
            r -= 1
            ans.append(query(l, r))
    print(*ans)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()