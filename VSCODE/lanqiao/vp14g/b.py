import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf

#include<bits/stdc++.h>




input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    a = [
    [1,1,0,1,0,1,1,1,1,1],
    [1,1,1,0,0,1,1,1,1,0],
    [1,1,0,0,1,0,1,1,1,1],
    [1,0,1,1,0,1,1,1,1,0],
    [1,0,1,0,1,1,1,1,0,0],
    [1,0,0,1,0,1,0,1,0,1],
    [1,1,1,1,1,1,1,1,1,0],
    [0,1,1,1,1,1,1,1,1,0],
    [0,1,1,0,1,0,1,1,1,1],
    [1,0,1,0,0,1,0,1,0,0],
  ]
    def check(x, y):
        return 0 <= x < 10 and 0 <= y < 10
    
    st = set()
    for i in range(10):
        for j in range(10):
            if a[i][j] == 0: continue
            for k in range(i + 1, 10):
                for p in range(j + 1):
                    if a[k][p] == 0: continue
                    if check(k + j - p, p + k - i) and check(i + j - p, j + k - i) and a[k + j - p][p + k - i] and a[i + j - p][j + k - i]:
                        st.add((j - p) * (j - p) + (i - k) * (i - k))
    print(len(st))
    


if __name__ == '__main__':
    solve()