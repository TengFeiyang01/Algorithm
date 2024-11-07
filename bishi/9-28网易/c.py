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

class Solution:
    def validTree(self, n: int, edges):
        if len(edges) != n - 1:
            return False  
        adj = {i: [] for i in range(n)}
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        st = set()

        def dfs(u, f):
            st.add(u)
            for v in adj[u]:
                if v == f: 
                    continue
                if v in st:
                    return False
                if not dfs(v, u): 
                    return False
            return True

        if not dfs(0, -1):
            return False
        return len(st) == n

def solve() -> None:
    n = sint()
    d = [ints() for _ in range(n-1)]
    print(Solution().validTree(n, d))


if __name__ == '__main__':
    solve()