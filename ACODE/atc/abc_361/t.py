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

def solve() -> None:
    m = sint()
    a = ints()
    s = input()
    
    def generateNewArray(arr, state, m):
        ans = []
        n = len(arr)
        state = list(state)

        mx = max(arr)
        cur = -inf
        pos = set()
        
        for i, (x, c) in enumerate(zip(arr, state)):
            if c == '1':
                pos.add(i)
                cur = max(cur, x)
        if cur == mx:
            return [mx] * m                

        for j in range(m):
            ans.append(cur)
            npos = set()
            for x in pos:
                if x + 1 < n and x + 1 not in pos and state[x + 1] == '0':
                    state[x + 1] == '1'
                    npos.add(x + 1)
                    cur = max(cur, arr[x + 1])
                pos = npos
        return ans
        
    print(*generateNewArray(a, s, m))
        

if __name__ == '__main__':
    solve()