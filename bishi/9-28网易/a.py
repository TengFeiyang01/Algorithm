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
    # 定义分隔符
    

class Solution:
    def countWords(self, s: str) ->int:
        separators = set([' ', '.', ',', '!', '?'])
            
        word = ""
        words_set = set()
        
        for char in s:
            if char in separators:
                if word.replace("'", "").isalpha():  
                    words_set.add(word.lower())
                word = "" 
            else:
                word += char 
        
        if word.replace("'", "").isalpha():
            words_set.add(word.lower())
        
        return len(words_set)

def solve() -> None:
    print(Solution().countWords(input()))

if __name__ == '__main__':
    solve()