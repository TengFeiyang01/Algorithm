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

from math import comb
k, m, n = map(int, input().split())
if k < m + n:
    print(0)
else:
    print(comb(m + n, m))

def solve() -> None:
    n = int(input())
    s = input()
    ok = True
    cnt = [0] * (n + 1)
    suf = 0
    for i in range(n - 1, -1, -1):
        if s[i] == 'e' and suf == 0:
            ok = False
        if s[i] == 'd':
            suf += 1
    suf = 0
    for i in range(n - 1, -1, -1):
        if s[i] == 'r' and suf == 0:
            ok = False
        if s[i] == 'e':
            suf += 1
    pre = 0
    for i in range(n):
        if s[i] == 'r':
            pre += 1
        if s[i] == 'e' and pre == 0:
            ok = False
    pre = 0

    for i in range(n):
        if s[i] == 'e':
            pre += 1
        if s[i] == 'd' and pre == 0:
            ok = False
    print("YES" if ok else "NO")

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        solve()