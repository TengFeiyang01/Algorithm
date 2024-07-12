import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from bisect import bisect_left, bisect_right
from functools import lru_cache
from collections import defaultdict
from math import inf
from typing import Counter
# import math
# import random
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

sys.setrecursionlimit(100000)

def solve() -> None:
    n, m = mint()
    a = ints()
    a.sort(reverse=True)
    a = [x * 2 for x in a]
    m *= 2
    ans = inf
    
    if sum(a) < m:
        print(-1)
        return
    
    f = Counter()
    n1 = n >> 1
    n1 -= 1

    def dfs1(u, s, cnt):
        nonlocal ans 
        if cnt >= ans or s > m: return
        if s == m:
            ans = min(ans, cnt)
            return
        if u >= n1:
            if s in f:
                f[s] = min(f[s], cnt)
            else:
                f[s] = cnt
            return
        dfs1(u + 1, s, cnt)
        dfs1(u + 1, s + a[u], cnt)
        dfs1(u + 1, s + a[u] // 2, cnt + 1)
    
    def dfs2(u, s, cnt):
        nonlocal ans
        if cnt >= ans or s > m: return
        if s == m:
            ans = min(ans, cnt)
            return
        if m - s in f:
            ans = min(ans, cnt + f[m - s])
            return
        if u >= n:
            return  
        dfs2(u + 1, s, cnt)
        dfs2(u + 1, s + a[u], cnt)
        dfs2(u + 1, s + a[u] // 2, cnt + 1)
    
    dfs1(0, 0, 0)
    dfs2(n1, 0, 0)
            
    print(ans if ans != inf else -1)
        
            

if __name__ == '__main__':
    solve()