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
    a, b = mint()
    res, i = 1, 2
    def dfs(x, y):
        if y == 0: return 1
        if y % 2 == 0: return (x % 9901 * dfs(x, y - 1) + 1) % 9901
        return (1 + pow(x, y // 2 + 1, 9901)) * dfs(x, y // 2) % 9901


    while i <= a:
        s = 0
        while a % i == 0:
            a //= i
            s += 1
        if s:
            res = res * dfs(i, s * b) % 9901
        i += 1
    if a == 0:
        res = 0
    print(res)


if __name__ == '__main__':
    solve()