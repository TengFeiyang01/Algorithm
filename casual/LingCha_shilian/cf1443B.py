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
    a, b = mint()
    s = input()
    ans = 0
    pre = -99999
    for i, c in enumerate(s):
        if c == '1':
            # 首次碰到1 答案是a
            # 再次碰到1 答案就是直接改a 连着一起改 (i-pre-1)*b+a 这里的a是之前的a
            ans += min(b*(i-pre-1), a)
            pre = i
    print(ans)


if __name__ == '__main__':
    _ = sint()
    for i in range(_):
        solve()