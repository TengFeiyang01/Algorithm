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
    n, q = mint()
    s = [[0] * (n + 2) for _ in range(n + 2)]

    for i in range(q):
        x1, y1, x2, y2 = mint()
        s[x1][y1] += 1
        s[x1][y2 + 1] -= 1
        s[x2 + 1][y1] -= 1
        s[x2 + 1][y2 + 1] += 1
        
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]
            print(s[i][j]&1, end='')
        print()
    

if __name__ == '__main__':
    solve()