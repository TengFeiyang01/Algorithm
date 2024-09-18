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

from collections import defaultdict
def dfs(a, m):
    dp = [float('inf')] * (m + 1)
    dp[0] = 0 

    paths = defaultdict(set)
    paths[0] = {tuple()}

    for i in range(1, m + 1):
        for power in a:
            if i >= power and dp[i - power] + 1 <= dp[i]:
                if dp[i - power] + 1 < dp[i]:
                    paths[i] = set()
                dp[i] = dp[i - power] + 1
                for path in paths[i - power]:
                    new_path = tuple(sorted(path + (power,)))
                    paths[i].add(new_path)
    
    if dp[m] == float('inf'):
        return -1

    return [list(config) for config in paths[m]]

def solve() -> None:
    a = list(map(int, input().split()))
    m = int(input())
    ans = dfs(a, m)
    if ans == -1:
        print(-1)
    else:
        ans.sort()
        for x in ans:
            print(*x)
    

if __name__ == '__main__':
    solve()