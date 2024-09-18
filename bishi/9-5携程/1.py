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
    n, k =  map(int, input().split())
    a = list(range(1, n+1))
    print(*a[:k-1],*a[k-1:][::-1])

if __name__ == '__main__':
    solve()