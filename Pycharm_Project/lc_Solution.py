import math
from collections import Counter, defaultdict, deque
from heapq import heappop, heappush, heapify, heapreplace, heappushpop, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from math import inf, gcd, lcm, log, log2, ceil, floor
from typing import List

import sortedcontainers
from sortedcontainers import SortedList, SortedDict
from itertools import accumulate, combinations, permutations, pairwise
from functools import lru_cache, reduce, cmp_to_key

# sys.set_int_max_str_digits(20000)  # 设置最大字符串位数
MOD = 10 ** 9 + 7
DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))


mod = 1000000007
class Solution:
    def numberOfSequence(self, n: int, sick: List[int]) -> int:
        sick = [-1] + sick + [n]
        ans = 1
        tot = 0
        for i in range(1, len(sick)):
            x = sick[i] - sick[i - 1] - 1
            if x == 0: continue
            cur = 0
            if sick[i - 1] == -1 or sick[i] == n:
                cur = 1
            else:
                cur = pow(2, x - 1, mod)
            ans *= comb(tot + x, x) * cur
            tot += x
        return ans % mod