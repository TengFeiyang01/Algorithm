import sys
import heapq
import itertools
import datetime
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    y, d = sint(), sint() - 1
    y = datetime.date(y, 1, 1)
    delta = datetime.timedelta(d)
    y += delta
    print(y.month)
    print(y.day)

if __name__ == '__main__':
    solve()