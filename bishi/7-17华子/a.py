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
        self.smallHeap = []
        self.bigHeap = []


    def addNum(self, num: int) -> None:
        if len(self.smallHeap) != len(self.bigHeap):
            heappush(self.smallHeap, num)
            heappush(self.bigHeap, -heappop(self.smallHeap))
        else:
            heappush(self.bigHeap, -num)
            heappush(self.smallHeap, -heappop(self.bigHeap))


    def findMedian(self) -> float:
        x = 0
        if len(self.smallHeap)==len(self.bigHeap):
            if self.smallHeap[0] <= self.bigHeap[0]:
                x = heappop(self.smallHeap)
            else:
                x = -heappop(self.bigHeap)
        else:
            x = heappop(self.smallHeap)
        if len(self.smallHeap) < len(self.bigHeap):
            heappush(self.smallHeap, -heappop(self.bigHeap))
        
         
        return x

def solve() -> None:
    n = sint()
    a = ints()
    a.sort()

        
        

if __name__ == '__main__':
    for _ in range(sint()):
        solve()
    
    