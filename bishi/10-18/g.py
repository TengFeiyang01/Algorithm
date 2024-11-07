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

def f1():
    for i in range(sint()):
        x, y = map(int, input().split(":"))
        x = (x - 8) % 24
        print('%02d:%02d' % (x, y))


def f2():
    n, m = mint()
    a = ints()
    def check(t):
        cnt = 1
        st = {}
        for x in a:
            if x not in st:
                if len(st) < t:
                    st.add(x)
                else:
                    st = {x}
                    cnt += 1
        return cnt <= m
    l, r =  0, n
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1
    print(l)

def f3():
    n = sint()
    a = ints()
    adj = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = mint()
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)
    ans = 0
    
    def dfs(u, fa):
        nonlocal ans
        mx, mx1 = 1, 1
        for v in adj[u]:
            if v != fa:
                p, q = dfs(v, u)
                if p + 1 >= mx:
                    mx1 = mx
                    mx = p + 1
                elif p + 1 > mx1:
                    mx1 = p + 1
        if fa == -1 or a[u] >= a[fa]:
            ans = max(ans, mx + mx1 - 1)
    dfs(0, -1)
    print(ans)

def solve() -> None:
    f1()

if __name__ == '__main__':
    solve()