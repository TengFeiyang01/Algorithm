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
    n, k = mint()
    a = ints()
    b = list(sorted(a[:]))
    pos = {x:i for i, x in enumerate(a)}
    st = set()
    i = 0
    cnt = 0
    while i < n:
        j = i + 1
        p = pos[b[i]] + 1
        while j < n and p < n and b[j] == a[p]:
            j += 1
            p += 1
        i = j
        cnt += 1
    if cnt <= k:
        print("True")
    else:
        print("False")
    
    

if __name__ == '__main__':
    for _ in range(sint()):
        solve()
        # 4 1 2 3 5