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
    for i in range(n):
        m = int(input())
        s = input()
        ok = False
        for j in range(3, m):
            if s[j-3:j] == 'aba':
                for k in range(j + 3, m):
                    if s[k-3:k] == 'aba':
                        ok = True
        print("YES" if ok else "NO")

if __name__ == '__main__':
    solve()