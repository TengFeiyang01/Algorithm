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
        x = int(input())
        for j in range(2, x+1):
            if x % j == 0:
                print(j)
                break


if __name__ == '__main__':
    solve()