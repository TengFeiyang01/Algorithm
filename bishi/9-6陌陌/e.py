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
# 110100 
# 110001 3
# 100011 4
# 000111 4

def get(s):
    cnt1 = 0  
    cnt0 = 0  
    sum = 0  
    
    for i in range(len(s)):  
        if i > 0 and s[i] == '1' and s[i - 1] == '0':  
            sum += cnt1 * (cnt0 + 1)  
            cnt0 = 0  
        if s[i] == '1':  
            cnt1 += 1  
        if s[i] == '0':  
            cnt0 += 1  
    
    if s[-1] == '0':  
        sum += cnt1 * (cnt0 + 1)  
    
    return sum  

def solve() -> None:
    print(get(input()))

if __name__ == '__main__':
    solve()