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
    n = sint()
    t = set()
    cnt = Counter()
    s = input()
    for i in range(n):
        p = input()
        t.add(p)
    ok = False
    l, r = 0, 0
    for x in t:
        if x == s:
            ok = True
        cnt[len(x)] += 1
        if len(x) < len(s):
            l += 1
            r += 1
        elif len(x) == len(s):
            r += 1
    if not ok:
        l = r
    else:
        l += 1
    print(l, r)
    

if __name__ == '__main__':
    solve()