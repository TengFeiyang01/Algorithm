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
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.n = n
        self.setCount = n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1
        return True

    def connected(self, x, y):
        x, y = self.find(x), self.find(y)
        return x == y

class Solution:
    def roadPlan(self, cityNumber: int, roadNumber: int, roadArray: List[List[int]]):
        uf = DSU(cityNumber)
        for x, y in roadArray:
            uf.union(x, y)
        st = set()
        for i in range(cityNumber):
            st.add(uf.find(i))
        return len(st)-1
            

def solve() -> None:
    s = Solution()
    print(s.roadPlan(20, 7, [[0, 1], [6, 9], [3, 8], [5, 11], [2, 12], [6, 10], [4, 8]]))


if __name__ == '__main__':
    solve()