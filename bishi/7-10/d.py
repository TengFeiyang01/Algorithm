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

class Tree:
    def __init__(self, x = 0, l = None, r = None) -> None:
        self.x = x
        self.l = l
        self.r = r

def solve() -> None:
    
    def solution(T):
        st = set()
        ans = 1
        def dfs(u, d):
            nonlocal ans
            ans = max(ans, d)
            if u.l and u.l.x not in st:
                st.add(u.l.x)
                dfs(u.l, d + 1)
                st.remove(u.l.x)
            if u.r and u.r.x not in st:
                st.add(u.r.x)
                dfs(u.r, d + 1)
                st.remove(u.r.x)
        st.add(T.x)
        dfs(T, 1)
        return ans
    
    tr = [Tree() for I in range(16)]
    v = [0, 1, 2, 2, 1, 2, 4, 1]
    for i in range(1, 8):
        tr[i].l = tr[i * 2]
        tr[i].r = tr[i * 2 + 1]
        tr[i].x = v[i]
    for i in range(4, 8):
        tr[i].l = None
        tr[i].r = None
    print(solution(tr[1]))
                


if __name__ == '__main__':
    solve()