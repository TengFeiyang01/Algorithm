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

dirs = [-1, 0, 1, 0, -1]

def solve() -> None:
    n = sint()
    k = sint()
    g = [ints() for i in range(n)]
    l, r = 0, 1000000
    
    def check(mx):
        q = deque()
        q.append((0, 0, 0))
        st = set()
        res = 1000000000
        while q:
            x, y, d = q.popleft()
            if x == n - 1 and y == n - 1:
                res = d
            for dx, dy in itertools.pairwise(dirs):
                i, j = x + dx, y + dy
                if 0 <= i < n and 0 <= j < n and (i, j) not in st and g[i][j] <= mx:
                    q.append((i, j, d + 1))
                    st.add((i, j))
        return res <= k
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1
    print(l)

if __name__ == '__main__':
    solve()