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
    s = input()
    i = 0
    def dfs():
        res = 0
        nonlocal i
        while i < len(s):
            if s[i] == '(':
                i += 1
                res += dfs()
                i += 1
            elif s[i] == '|':
                i += 1
                res = max(res, dfs())
            elif s[i] == ')':
                break
            else:
                i += 1
                res += 1
        return res
    print(dfs())

if __name__ == '__main__':
    solve()