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
    a = ints()
    odd = even = 0
    oddCnt = evenCnt = 0
    for i, x in enumerate(a):
        if i % 2 == 0:
            even += x
            evenCnt += 1
        else:
            odd += x
            oddCnt += 1
    if odd % oddCnt == 0 and even % evenCnt == 0 and odd // oddCnt == even // evenCnt:
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    for _ in range(int(input())):
        solve()