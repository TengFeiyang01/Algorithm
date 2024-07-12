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
    st = {'a', 'e', 'i', 'o', 'u'}
    n = int(input())
    s = input()
    ans = 0
    i = 0
    while i < n:
        j = i + 1
        while j < n and not (s[j - 1] in st and s[j] in st):
            j += 1
        ans = max(ans, j - i)
        i = j
    print(ans)
        

if __name__ == '__main__':
    solve()