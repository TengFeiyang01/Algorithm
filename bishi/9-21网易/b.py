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
    ans = 25
    t = "AcMer"
    for i in range(n-4):
        cur = 0
        for j in range(5):
            if s[i+j] != t[j]:
                cur += 5
        ans = min(ans, cur)
    print(ans)


if __name__ == '__main__':
    solve()