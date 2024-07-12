import functools
import heapq
import itertools
import random
import sys
from typing import Counter

# import itertools
# import math
# import os
# import random

from collections import defaultdict
from functools import lru_cache
from bisect import bisect_left, bisect_right
from heapq import heapify, heappop, heappush
from io import BytesIO, IOBase
from math import inf
from string import *

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

# MOD = 998244353
MOD = 10 ** 9 + 7
# DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))

sys.setrecursionlimit(3 * 10 ** 5)


def solve() -> None:
    s = input()
    t = input()
    n = len(s)
    i = n - 1
    while i >= 0 and s[i] == t[i]:
        i -= 1

    if s == t:
        print(0)
    elif len(set(s[:i+1])) == 1:
        print(1)
        print(2, i+1, s[i])
    elif len(set(t[:i+1])) == 1:
        print(1)
        print(1, i+1, t[i])
    else:
        print(2)
        print(1, n, 'a')
        print(2, n, 'a')



if __name__ == '__main__':
    solve()
