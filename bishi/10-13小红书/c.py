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

    d = [0] * n
    st = set()
    for i in range(n - 1):
        u, v = map(int, input().split())
        adj[u-1].append(v-1)
        adj[v-1].append(u-1)
        d[u-1] += 1
        d[v-1] += 1
        
    ans = 0
    for i in range(n):
        if d[i] == 1:
            ans += 1
            st.add(i)
    
    ok = 1
    def dfs(u, fa):
        for v in adj[u]:
            if v == fa:
                continue
            if d[u] == 2 and v in st:
                ok = 0
            dfs(v, u)
    dfs(0, -1)
    print(ans-ok)      
    

if __name__ == '__main__':
    solve()