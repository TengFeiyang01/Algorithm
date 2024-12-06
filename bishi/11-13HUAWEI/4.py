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
    s = [set() for _ in range(n)]
    for i in range(n):
        t = sint()
        for j in range(t):
            s[i].add(input())
    for i in range(n):
        mx = pos = 0
        for j in range(n):
            cnt = 0
            if i == j:
                continue
            for p in s[i]:
                if p in s[j]:
                    cnt += 1
            if cnt > mx:
                mx = cnt
                pos = j
        print(pos + 1, mx)


if __name__ == '__main__':
    solve()