import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from collections import *
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, m = mint()
    a = ints()
    ans = -inf
    s = [0] * (n + 1) 
    for i in range(n):
        s[i + 1] = s[i] + a[i]
    q = deque()
    q.append(0)
    for i in range(1, n+1):
        while q and i - q[0] > m: q.popleft()
        ans = max(ans, s[i] - s[q[0]])
        while q and s[i] <= s[q[-1]]: q.pop()
        q.append(i)
    print(ans)
    

if __name__ == '__main__':
    solve()