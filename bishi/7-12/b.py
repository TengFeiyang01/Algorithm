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
    def bestAverageGrade(scores):
        totScore = {}
        testCount = {}
        for name, score in scores:
            if name not in totScore:
                totScore[name] = int(score)
                testCount[name] = 1
            else:
                testCount[name] += 1
                totScore[name] += int(score)
            
        ans = 0
        for k, v in totScore.items():
            ans = max(ans, v // testCount[k])
        return ans
    
    tc1 = [
        ["Bob", "72"],
          ["Alice", "61"],
          ["Eric", "24"],
          ["Eric", "100"],
          ["Eric", "100"],
          ]
    tc2 = [["Alice", "68"], ["Tom", "22"], ["Cris", "87"], ["July", "64"]]
    
    tc = [tc1, tc2]
    
    for t in tc:
        print(bestAverageGrade(t))

    
if __name__ == '__main__':
    solve()