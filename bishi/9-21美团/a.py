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

def solve():
    t = int(input())
    while t:
        t -= 1
        x = int(input())
        l, r = 0, 60
        while l < r:
            mid = l +  r >> 1
            if (2**mid - 0**mid)//2+1 >= x:
                r = mid
            else:
                l = mid + 1
        print(l+1)


def solve1() -> None:
    t = sint()
    for i in range(t):
        n = int(input())
        if n == 1:
            print(1)
            continue
        ans = tot = 2
        while tot < n:
            tot = tot * 2 - 1
            ans += 1
        print(ans)

if __name__ == '__main__':
    solve1()