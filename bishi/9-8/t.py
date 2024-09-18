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
    d = sint()
    ans = inf
    def dfs(a):
        if len(a) > 12:
            return
        for i in range(1, d+1):
            a.append(i)
            dfs(a)
            a.pop()
        ok = True
        # print(len(a), a)
        st = set()
        for i in range(1, len(a)):
            st.add((a[i], a[i - 1]))
            st.add((a[i - 1], a[i]))
        for i in range(1, d+1):
            for j in range(i+1, d+1):
                if (i, j) not in st:
                    ok = False
        if ok:
            nonlocal ans
            ans = min(ans, len(a))
    dfs([])
    print(ans)
    
if __name__ == '__main__':
    solve()