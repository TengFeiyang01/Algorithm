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
    n, f = mint()
    a = [0] * n
    for i in range(n):
        a[i] = sint()

    def check(k):
        b = [0] * (n + 1)
        for i in range(1, n + 1):
            b[i] = b[i - 1] + a[i - 1] - k
        mi = 0
        i, j = 0, f
        while j <= n:
            mi = min(mi, b[i])
            if b[j] >= mi:
                return True
            i += 1
            j += 1
        return False


    l, r = 0.0, 2000.0
    while r - l > 1e-6:
        mid = (l + r) / 2
        if check(mid):
            l = mid
        else:
            r = mid

    print(int(r * 1000))


    
if __name__ == '__main__':
    solve()