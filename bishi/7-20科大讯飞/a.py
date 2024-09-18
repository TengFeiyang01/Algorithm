import heapq

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


class MedianFinder:
    def __init__(self):
        self.small = [] # 小根堆
        self.large = [] # 大根堆

    def addNum(self, num: int) -> None:
        heapq.heappush(self.large, -num)
        heapq.heappush(self.small, -heapq.heappop(self.large))
        if len(self.large) < len(self.small):
            heapq.heappush(self.large, -heapq.heappop(self.small))

    def findMedian(self) -> float:
        x = -self.large[0]
        heapq.heappop(self.large)

        if len(self.small) > len(self.large):
            heapq.heappush(self.large, -heapq.heappop(self.small))
            
        return x
    
def solve() -> None:
    n = sint()
    a = ints()
    mf = MedianFinder()
    for x in a:
        mf.addNum(x)
    for i in range(n):
        print(mf.findMedian(), end=' ')


if __name__ == '__main__':
    solve()
