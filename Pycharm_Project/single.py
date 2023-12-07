import functools
import heapq
import itertools
import sys
from typing import Counter

# import itertools
# import math
# import os
# import random

from collections import defaultdict
from functools import lru_cache
from bisect import bisect_left, bisect_right

# from heapq import heapify, heappop, heappush
# from io import BytesIO, IOBase
# from string import *

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

MOD = 998244353
# MOD = 10 ** 9 + 7
# DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))

sys.setrecursionlimit(3 * 10 ** 5)

from types import GeneratorType


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


import re





def solve() -> None:
    n = 100
    a, b = 2, 3
    ans = 1
    for i in range(n):
        ans *= (a + 1) * b
        ans = ans % 10
        a *= 2
        b *= 3

        print(ans, end=' ')

if __name__ == '__main__':
    solve()
