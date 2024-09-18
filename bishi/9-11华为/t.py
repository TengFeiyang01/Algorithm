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
    st = set()
    nums1 = ints()
    nums2 = ints()
    
   #Method 1: Use Python's built-in set&function
    #Can quickly convert nums1 and nums2 into a set
    #Then directly calculate the intersection of the set
    #Time complexity O (n) Space complexity O (n)
    print(list(set(nums1)&set(nums2)))
    # Method2: Manual calc 
    # Use a collection record nums1, where each number is calculated only once
    # Determine whether each number in nums1
    # and put the element into a new set
    st = set()
    for x in nums1:
        if x not in st:
            st.add(x)
    ans = set()
    for x in nums2:
        if x not in ans and x in st:
            ans.add(x)        
    print(list(ans))
    
if __name__ == '__main__':
    solve()