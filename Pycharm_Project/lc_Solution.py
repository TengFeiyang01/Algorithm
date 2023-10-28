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

Counter().most_common()
class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        s = sortedcontainers.SortedList()
        ans = [-1, -1]
        for i, x in enumerate(nums):
            s.add((nums[i - indexDifference], i - indexDifference))
            if i >= indexDifference:
                if len(s):
                    if abs(s[0][0] - x) >= valueDifference:
                        return [s[0][1], i]
                    if abs(s[-1][0] - x) >= valueDifference:
                        return [s[-1][1], i]
        return ans

