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
    n = sint()
    a = [ints() for _ in range(n)]
    a.sort(key=lambda x: (x[0], x[1]))
    r1, r2 = -1, -1

    for l, r in a:
        if l > r1:
            r1 = r
        elif l > r2:
            r2 = r
        else:
            print("NO")
            return
    print("YES")

    

if __name__ == '__main__':
    solve()