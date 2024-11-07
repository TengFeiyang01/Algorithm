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


# from functools import cmp_to_key

# def compare(x, y):
#     if x + y < y + x:
#         return -1
#     elif x + y > y + x:
#         return 1
#     else:
#         return 0
    

# def compare1(x, y):
#     if x + y < y + x:
#         return 1
#     elif x + y > y + x:
#         return -1
#     else:
#         return 0

# def smallestNumber(a):
#     positives = [num for num in a if num >= 0]
#     negatives = [num for num in a if num < 0]
    
#     if negatives:
#         max_negative = str(max(negatives))
#     else:
#         max_negative = ""
#     str_positives = list(map(str, positives))
#     if not negatives:
#         str_positives.sort(key=cmp_to_key(compare))
#     else:
#         str_positives.sort(key=cmp_to_key(compare1))
#     result = max_negative + ''.join(str_positives)
#     return result.lstrip('0') or '0'


from functools import cmp_to_key

def cmp(x, y, reverse=False):
    if reverse:
        return 1 if x + y < y + x else -1 if x + y > y + x else 0
    return -1 if x + y < y + x else 1 if x + y > y + x else 0



def solve() -> None:
    a = list(map(int, input().split()))
    res = ""
    pos = [str(num) for num in a if num >= 0]
    ok = False
    if min(a) < 0:    
        res += str(min(a))
        ok = True
        
    pos.sort(key=cmp_to_key(lambda x, y: cmp(x, y, reverse=ok)))
    
    res += ''.join(pos)
    print(res.lstrip('0') or '0')
    
if __name__ == '__main__':
    solve()