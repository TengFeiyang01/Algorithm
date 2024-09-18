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
    a = list(map(int, input().split()))

    s = sum(a)
    ans = []
    for i in range(n):
        s2 = s - a[i]
        avg = s2 // (n - 1)
        if avg * (n - 1) == s2:
            ans.append(0)
        else:
            ans.append(1)
    print(*ans)
            
if __name__ == '__main__':
    solve()