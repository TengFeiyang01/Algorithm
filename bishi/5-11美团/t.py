import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

from typing import*

class Solution:
    def countOne(self, numbers: List[int]) -> int:
        ans = 0
        for x in numbers:
            while x != 1:
                # x = x.bit_count()
                x = bin(x).count('1')
                ans += 1
        return ans


    

def solve() -> None:
    s = Solution()
    print(s.countOne([9, 2]))

if __name__ == '__main__':
    solve()