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


def generateNewArray(arr, state, m):
    ans = []
    n = len(arr)
    state = list(state)
    h = []
    for i, (x, c) in enumerate(zip(arr, state)):
        if c == '1':
            heappush(h, (-x, i))
            
    ans = []
    for j in range(m):
        x, i = heappop(h)
        ans.append(-x)
        if i and state[i - 1] == '0':
            heappush(h, (-arr[i - 1], i - 1))
            state[i - 1] = '1'
    return ans

