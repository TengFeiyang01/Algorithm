import sys
from typing import Counter

import itertools

# import math
# import os
# import random
# from bisect import bisect, bisect_left
# from collections import *
# from functools import reduce
# from heapq import heapify, heappop, heappush
# from io import BytesIO, IOBase
# from string import *

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


# MOD = 998244353
# MOD = 10 ** 9 + 7
# DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))

def solve() -> None:
    n = sint()

    def f(x):
        i, s, y = 2, 1, x
        while i * i <= x:
            if x % i == 0:
                t = 1
                while x % i == 0:
                    t *= i
                    x //= i
                s += t
            i += 1
        if x > 1:
            s += x
        return y != s
    ans = 0
    while n:
        ans += 1
        if f(n):
            break
        n //= 2
    print(ans)


for _ in range(int(input())):
    solve()
