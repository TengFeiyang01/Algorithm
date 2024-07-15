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

N = 1000010
s = [0] * (N + 1)
s[0] = 1
for i in range(1, N):
    s[i] = s[i - 1]
    if len(set(str(i))) == len(str(i)):
        s[i] += 1

def countNumbers(arr):
    ans = []
    for l, r in arr:
        print(s[r] - s[l - 1])

def solve() -> None:
    print(countNumbers([[1, 20], [9, 19]]))
    
if __name__ == '__main__':
    solve()