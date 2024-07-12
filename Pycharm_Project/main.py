import bisect
import itertools
import sys

import math
import os
import random

from itertools import accumulate, pairwise, permutations, combinations
from typing import Counter
from collections import *
from functools import reduce
from heapq import heapify, heappop, heappush
from io import BytesIO, IOBase
from string import *
from math import comb


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


# MOD = 10 ** 9 + 7
DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))


def solve() -> None:
    n = 5
    b = list(range(n))
    for a in permutations(b):
        res = list(b[::-1])
        x = 10000
        for p in permutations(b):
            p = list(p)
            if x > sum(abs(p[i] - a[p[(i + 1) % n]]) for i in range(n)):
                x = sum(abs(p[i] - a[p[(i + 1) % n]]) for i in range(n))
                res = p
            elif x == sum(abs(p[i] - a[p[(i + 1) % n]]) for i in range(n)):
                res = min(res, list(p))
            # print(sum(abs(p[i] - a[p[(i + 1) % n]]) for i in range(n)), p)
        print(a, x, res)


if __name__ == '__main__':
    solve()
