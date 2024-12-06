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


def dfs(n, m) -> int:
    def backtrack(row: int):
        if row == n:
            return 1
        count = 0
        for i in range(m):
            if i in columns or row - i in diagonal1 or row + i in diagonal2:
                continue
            queens[row] = i
            columns.add(i)
            diagonal1.add(row - i)
            diagonal2.add(row + i)
            count += backtrack(row + 1)
            columns.remove(i)
            diagonal1.remove(row - i)
            diagonal2.remove(row + i)
        return count

    queens = [-1] * n
    columns = set()
    diagonal1 = set()
    diagonal2 = set()
    return backtrack(0)

def solve() -> None:
    N, M = map(int, input().split())
    print(dfs(N, M))



if __name__ == '__main__':
    solve()