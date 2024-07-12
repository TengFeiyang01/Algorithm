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


def solve() -> None:
    n = sint()
    st = []
    for i in range(n):
        x = sint()
        while st and st[-1] >= x: st.pop()
        if st: print(st[-1], end=' ')
        else: print(-1, end=' ')
        st.append(x)
        

if __name__ == '__main__':
    solve()