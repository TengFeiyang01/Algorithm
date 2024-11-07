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


from bisect import *
    def count_perfect_pairs(arr):
        pos = [abs(x) for x in arr if x != 0]
        cnt = Counter(arr)
        n = len(arr)
        ans = 0
        # if 0 in cnt:
            # ans += cnt[0] * (n - cnt[0])
        pos.sort()
        for i, x in enumerate(pos):
            p = (x + 1) // 2
            q = x * 2
            ans += bisect_right(pos, q) - i - 1
        return ans

arr = [-9, -2, 1, 6]
# arr = [2, 1, 0]
result = count_perfect_pairs(arr)
print(result)