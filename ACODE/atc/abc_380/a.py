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
    s = list(input())
    s.sort()
    s = "".join(s)
    print("Yes" if s == "122333" else "No")


if __name__ == '__main__':
    solve()