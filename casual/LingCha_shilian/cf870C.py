import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
# from typing import Counter
# import math
# import random
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
from math import inf


def solve() -> None:
    t = sint()
    for i in range(t):
        n = sint()
        if n == 2 or n == 5 or n == 7 or n == 11:
            print(-1)
        else:
            print(n // 4 - n % 2)

    

if __name__ == '__main__':
    solve()