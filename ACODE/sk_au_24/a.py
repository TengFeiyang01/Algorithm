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
    p = 3
    p3 = set()
    while p <= 10**18:
        p3.add(p)
        p *= 3
    p = 5
    p5 = set()
    while p <= 10**18:
        p5.add(p)
        p *= 5
    
    for i in range(sint()):
        n = sint()
        ok = False
        for x in p3:
            if n - x in p5:
                ok = True
        print("Yes" if ok else "No")

if __name__ == '__main__':
    solve()