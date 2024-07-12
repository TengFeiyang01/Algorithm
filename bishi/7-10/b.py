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
    def solution(A, K):
        n = len(A)
        for i in range(n - 1):
            if A[i] + 1 < A[i + 1]:
                return False
            
        if A[0] != 1 or A[n - 1] != K:
            return False
        else:
            return True
    
    print(solution([1, 1, 2, 3], 3))

if __name__ == '__main__':
    solve()