import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf, gcd


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = sint()
    
    def dfs(a, b, c, d):
        if a + c > n: return
        dfs(a, b, a + c, b + d)
        print(f"{b+d}/{a+c}")
        dfs(a + c, b + d, c, d)

    print("0/1")
    dfs(1, 0, 1, 1)
    print("1/1")


if __name__ == '__main__':
    solve()