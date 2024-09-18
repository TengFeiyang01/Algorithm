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
    # n = sint()
    x = ints()
    y = ints()
    
    dd_x = defaultdict(list) 
    dd_y = defaultdict(list)
    n = len(x)
    for i in range(n):
      curX, curY = x[i], y[i]
      dd_x[curX].append(curY)
      dd_y[curY].append(curX)
    
    cnt = 0
    for key, value in dd_x.items():
      value.sort()
    for key, value in dd_y.items():
      value.sort()
    
    for i in range(n):
      curX, curY = x[i], y[i]
      ys = dd_x[curX]
      xs = dd_y[curY] 
      if curY != ys[0] and curY != ys[-1] and curX != xs[0] and curX != xs[-1]:
        cnt += 1
    print(cnt)
    return cnt

    
    
    

if __name__ == '__main__':
    solve()