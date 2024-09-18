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


def get(a, b):
    ans = 0
    while b:
        ans += a // b
        a, b = b, a % b
    return ans - 1

def solve() -> None:
    res = 0
    n = int(input())
    for i in range(n):
        x, y = map(int, input().split())
        res += get(x, y)
    print(0)
    print(res)

if __name__ == '__main__':
    solve()