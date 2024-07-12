import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
import datetime


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    try:
        s = input()
        t = input()
        while s != "" and t != "":
            d1 = datetime.datetime(int(s[:4]), int(s[4:6]), int(s[6:]))
            d2 = datetime.datetime(int(t[:4]), int(t[4:6]), int(t[6:]))
            if d1 >= d2:
                print((d1 - d2).days + 1)
            else:
                print((d2 - d1).days + 1)
            s = input()
            t = input()
    except EOFError:
        pass

if __name__ == '__main__':
    solve()