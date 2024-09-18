import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache, cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, m = mint()
    
    mx = 0
    @cache
    def dfs(x, y, cur):
        nonlocal mx
        mx = max(mx, cur)
        if max(x, y) < cur:
            return 1
        ans = 0
        if x >= cur:
            ans += dfs(x - cur, y, cur + 1)
        if y >= cur:
            ans += dfs(x, y - cur, cur + 1)
        return ans
    
    @cache
    def get(x, y, cur):
        if max(x, y) < cur:
            return cur == mx
        ans = 0
        if x >= cur:
            ans += get(x - cur, y, cur + 1)
        if y >= cur:
            ans += get(x, y - cur, cur + 1)
        return ans
    
    ans = dfs(n, m, 1)
    print(get(n, m, 1))

if __name__ == '__main__':
    solve()