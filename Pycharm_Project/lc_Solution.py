import random
import sys
from collections import Counter, defaultdict, deque
from heapq import heappop, heappush, heapify, heapreplace, heappushpop, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from math import inf, gcd, lcm
from sortedcontainers import SortedList, SortedDict
from itertools import *
from typing import *
from functools import cache

MOD = 10 ** 9 + 7
DIR = [(0, 1), (0, -1), (1, 0), (-1, 0)]
sys.setrecursionlimit(5000000)


class Solution:
    def countKConstraintSubstrings(self, s: str, k: int, queries: List[List[int]]) -> List[int]:
        one = [-1]
        zero = [-1]
        n = len(s)
        for i, x in enumerate(s):
            if x == '1':
                one.append(i)
            else:
                zero.append(i)
        one.append(n)
        zero.append(n)
        # [p, p, p, .. p]
        #   l        r















