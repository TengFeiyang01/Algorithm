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


def solve() -> None:
    n = sint()
    nums1 = ints()
    nums2 = ints()
    ans = same = 0
    cnt = Counter()
    for i, (a, b) in enumerate(zip(nums1, nums2)):
        if a == b:
            same += 1
            ans += i
            cnt[a] += 1

    m = lead = 0
    for k, v in cnt.items():
        if v * 2 > same:
            m = v * 2 - same
            lead = k
            break
    for i, (a, b) in enumerate(zip(nums1, nums2)):
        if m and a != b and a != lead and b != lead:
            ans += i
            m -= 1
    print(-1 if m else ans)

if  __name__ == '__main__':
    solve()