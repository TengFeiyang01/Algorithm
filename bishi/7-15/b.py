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



def getSmallestString(word, substr):
    n = len(word)
    m = len(substr)
    ans = None
    for i in range(n - m + 1):
        ok = True
        for j in range(i, i + m):
            if word[j] != '?' and word[j] != substr[j - i]:
                ok = False
        if ok:

            cur = (word[:i] + substr + word[i+m:]).replace('?', 'a')
            if not ans or ans > cur:
                ans = cur
    return '-1' if not ans else ans  


def solve() -> None:
    getSmallestString("s?f??d?j", "abc")
    getSmallestString("??c???er", "deciph")
    getSmallestString("as?b?e?gf", "dbk")
    
if __name__ == '__main__':
    solve()