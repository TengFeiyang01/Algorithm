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
    s = input()
    n = len(s)
    a, b = [], []
    x = 0
    for i in range(n):
        if '0' <= s[i] <= '9':
            x = x * 10 + int(s[i])
        else:
            a.append(x)
            x = 0
            b.append(s[i])
    a.append(x)
    x, y = 0, 0
    a = a[1:]
    for d, op in zip(a, b):
        if op == '<':
            x -= d
        elif op == '>':
            x += d
        elif op == '^':
            y += d
        else:
            y -= d
    print(x, y)

if __name__ == '__main__':
    solve()