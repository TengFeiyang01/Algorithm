import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
# from typing import Counter
# import math
# import random
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))



def solve() -> None:
    n = sint()
    l = [0] * n
    r = [0] * n
    for i in range(n):
        l[i], r[i] = mint()
    l.sort(reverse=True)
    r.sort()

    i = ans = 0
    while l[i] > r[i]:
        ans += (n - 1 - 2 * i) * (l[i] - r[i])
        i += 1
    print(ans)

if __name__ == '__main__':
    solve()