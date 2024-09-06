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


# def solve():
#     n, m = mint()
#     s = [input() for _ in range(n)]
#     ok = True
#     for i in range(n):
#         for j in range(m//2):
#             if s[i][j] != s[i][m - 1 - j]:
#                 ok = False
#     print("YES" if ok else "NO")
#     ok = True
#     for j in range(m):
#         for i in range(n//2):
#             if s[i][j] != s[n - 1 - i][j]:
#                 ok = False
#     print("YES" if ok else "NO")


def solve():
    n = int(input())
    ans = []
    for i in range(n):
        s = list(input())
        if s[0] == s[0].lower():
            if s.count('_') == 0:
                res = []
                for c in s:
                    if c.upper() == c.upper():
                        res.append("_")
                        res.append(c.lower())
                    else:
                        res.append(c)
                ans.append("".join(res))
            else:
                ok = True
                for i in range(1, len(s)):
                    if s[i - 1] == '_' and s[i] == s[i].upper():
                        ok = False
                if ok:
                    ans.append("".join(s))
                else:
                    ans.append("indistinct")
        else:
            ans.append("indistinct")
    for x in ans:
        print(x)




if __name__ == '__main__':
    solve()