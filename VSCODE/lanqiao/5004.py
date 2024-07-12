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
    a = ints()
    for i in range(1, n):
        a[i] ^= a[i - 1]
    ans = 0
    for i in range(21):
        c0, c1 = 1, 0
        for x in a:
            if x >> i & 1:
                c1 += 1
            else:
                c0 += 1
        ans += c0 * (n + 1 - c0) * (1 << i)
    print(ans)
    
if __name__ == '__main__':
    solve()