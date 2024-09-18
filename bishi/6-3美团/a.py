import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from collections import *
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = sint()
    ans = [1] * 2 + [2] * (n - 2)
    print(*ans)
    


if __name__ == '__main__':
    solve()