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
    
    def check(t):
        return sum(max(0, (x - t) // y + 1) for x, y in a) >= m

    l, r = 0, int(1e9)
    while l < r:
        mid = l + r + 1 >> 1
        if check(mid):
            l = mid
        else:
            r = mid - 1
    
    ans = cnt = 0
    for x, y in a:
        if x >= r:
            c = (x - r) // y + 1
            ed = x - (c - 1) * y
            cnt += c
            ans += (x + ed) * c // 2
    
    print(ans - (cnt - m) * r)


if __name__ == '__main__':
    solve()