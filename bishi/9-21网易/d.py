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
    t = int(input())
    for _ in range(t):
        a = list(map(int, input().split()))
        x = gcd(*a)
        if x == 1:
            print(-1)
        else:
            i = 2
            p = []
            while i * i <= x:
                if x % i == 0:
                    p.append(i)
                    while x % i == 0:
                        x //= i
                i += 1
            if x > 1:
                p.append(x)
            print(min(p))
                        

if __name__ == '__main__':
    solve()