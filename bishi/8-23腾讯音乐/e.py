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

class ListNode:
    def __init__(self, x) -> None:
        self.val = x
        self.next = None

class Solution:
    def merge(self, a: ListNode)->int:
        ans = cnt = 0
        pre = a.val
        if not a or not a.next: return 0
        p, q = a, a.next
        cnt = 1
        while q:
            if (q.val != 0) == (p.val != 0):
                cnt += 1
            else:
                ans += cnt - 1
                cnt = 1
            p = q
            q = q.next
        if cnt > 1:
            ans += cnt - 1
        return ans
 


def solve() -> None:
    a = [0, 0, 1, 2]
    

if __name__ == '__main__':
    solve()