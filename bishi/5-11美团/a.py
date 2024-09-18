import sys
from math import inf
from collections import *

from functools import reduce


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    T = int(input())
    for _ in range(T):
        k, r = map(int, input().split())

        ans = 1
        if k >= 4 and r >= 3:
            ans += k // 4
        if k >= 4 and r >= 7:
            ans += k // 4

        if r >= 7:
            ans += ((k // 2) ** 2 + 1) // 2
        print(ans)
        
        
if __name__ == '__main__':
    solve()