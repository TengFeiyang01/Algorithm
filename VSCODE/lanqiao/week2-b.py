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
    T = sint()
    for t in range(1 , T + 1) :
        n = sint()
        s = input()
        a = []
        a.append(0)
        for i in s :
            x = ord(i) - ord('0')
            a.append(x)
        for i in range(1 , n + 1) :
            a[i] += a[i - 1]
        res = 0
        x = (n + 1) // 2
        for i in range(1 , n + 1) :
            r = i + x - 1
            if r > n :
                break
            res = max(res , a[r] - a[i - 1])
        print("Case #{}: {}".format(t , res))



if __name__ == '__main__':
    solve()