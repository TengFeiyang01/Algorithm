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

class SegmentTree:
    def __init__(self, prices):
        self.n = len(prices)
        self.tree = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)
        self.build(prices, 0, 0, self.n - 1)

    def build(self, prices, node, start, end):
        if start == end:
            self.tree[node] = prices[start]
        else:
            mid = (start + end) // 2
            self.build(prices, 2 * node + 1, start, mid)
            self.build(prices, 2 * node + 2, mid + 1, end)
            self.tree[node] = min(self.tree[2 * node + 1], self.tree[2 * node + 2])

    def update(self, idx, value, node, start, end):
        self.apply_lazy(node, start, end) 
        if start == end:
            self.tree[node] = value
        else:
            mid = (start + end) // 2
            if start <= idx <= mid:
                self.update(idx, value, 2 * node + 1, start, mid)
            else:
                self.update(idx, value, 2 * node + 2, mid + 1, end)
            self.tree[node] = min(self.tree[2 * node + 1], self.tree[2 * node + 2])

    def range_update(self, value, node, start, end):
        if start != end:
            self.lazy[node] = max(self.lazy[node], value)
            self.tree[node] = max(self.tree[node], value)

    def apply_lazy(self, node, start, end):
        if self.lazy[node] > 0:
            self.tree[node] = max(self.tree[node], self.lazy[node])
            if start != end:
                self.lazy[2 * node + 1] = max(self.lazy[2 * node + 1], self.lazy[node])
                self.lazy[2 * node + 2] = max(self.lazy[2 * node + 2], self.lazy[node])
            self.lazy[node] = 0

    def update_price(self, idx, value):
        self.update(idx, value, 0, 0, self.n - 1)

    def update_min(self, value):
        self.range_update(value, 0, 0, self.n - 1)

    def get_price(self, idx):
        return self.get_price_util(idx, 0, 0, self.n - 1)

    def get_price_util(self, idx, node, start, end):
        self.apply_lazy(node, start, end) 
        if start == end:
            return self.tree[node]
        else:
            mid = (start + end) // 2
            if start <= idx <= mid:
                return self.get_price_util(idx, 2 * node + 1, start, mid)
            else:
                return self.get_price_util(idx, 2 * node + 2, mid + 1, end)

    def get_prices(self):
        return [self.get_price_util(i, 0, 0, self.n - 1) for i in range(self.n)]
    
def getFinalPrice1(price, queries):
    segment_tree = SegmentTree(price)
    
    for query in queries:
        if query[0] == 1:
            x, v = query[1] - 1, query[2]  # x为1基索引
            segment_tree.update_price(x, v)
        elif query[0] == 2:
            v = query[1]
            segment_tree.update_min(v)

    return segment_tree.get_prices()

def getFinalPrice(price, queries):
    n = len(price)
    m = len(queries)
    mx = -10**9
    pos = m-1
    for i in range(m - 1, -1, -1):
        if queries[i][0] == 2:
            if mx < queries[i][1]:
                mx = queries[i][1]
                pos = i
    for i in range(pos):
        if queries[i][0] == 1:
            price[queries[i][1]-1] = queries[i][2]

    for i in range(n):
        if price[i] < mx:
            price[i] = mx
    for i in range(pos+1, m):
        if queries[i][0] == 1:
            price[queries[i][1]-1] = queries[i][2]
            
    
    return price
    

def solve() -> None:
    a = ints()
    p = sint()
    q = [ints() for _ in range(p)]
    print(getFinalPrice(a, q))

if __name__ == '__main__':
    solve()