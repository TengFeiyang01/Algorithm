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
    n = int(input())
    adj = [[] for _ in range(n)]
    a = list(map(int, input().split()))
    i = 0
    p = q = 0
    w = [0] * n
    pos = {}
    while i < 2 * n:
        if a[i] != -1:
            w[p] = a[i]
            pos[p] = i
            p += 1
            i += 1
        else:
            j = i + 1
            while j < 2 * n and a[j] != -1:
                pos[p] = j
                w[p] = a[j]
                adj[q].append(p)
                p += 1
                j += 1
            q += 1
            i = j

    ans = 0
    res = [0] * (2 * n)
    def dfs(u):
        s = w[u]
        for v in adj[u]:
            s += dfs(v)
        nonlocal a
        a[pos[u]] = s
        return s
    dfs(0)
    print(*a)    

if __name__ == '__main__':
    solve()