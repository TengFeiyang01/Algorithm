import sys

sys.setrecursionlimit(100000)
from collections import *
from math import *
from functools import *
from itertools import *
from typing import List

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        mx = []
        for r, x in enumerate(nums):
            while q and r - k + 1 > q[0]:
                q.popleft()
            while q and nums[q[-1]] <= x:
                q.pop()
            q.append(r)
            if r - k + 1 >= 0:
                mx.append(nums[q[0]])
        q = deque()
        mn = []
        for r, x in enumerate(nums):
            while q and r - k + 1 < q[0]:
                q.popleft()
            while q and nums[q[-1]] >= x:
                q.pop()
            q.append(r)
            if r - k + 1 >= 0:
                mx.append(nums[q[0]])
        return [x-y for x, y in zip(mx, mn)]

def solve() -> None:
    pass


if __name__ == '__main__':
    solve()