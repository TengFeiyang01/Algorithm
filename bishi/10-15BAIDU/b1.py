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
    a, b, c, d, k = map(int, input().split())
    arr = [a, b, c, d]
    for i in range(k):
        arr.sort()
        arr[0] += 1
    ans = 1
    for x in arr:
        ans *= x

    print(ans)

if __name__ == '__main__':
    for _ in range(int(input())):
        solve()