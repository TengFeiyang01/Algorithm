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
    n = int(input())  # 第一行输入数组元素个数
    a = list(map(int, input().split())) # 第二行输入数组
    t = int(input()) # 第三行输入目标
    a.sort() # 排序
    l, r = 0, n-1  # 二分边界
    while l < r:
        mid = l + r >> 1
        if a[mid] >= t:  # 当前的大于等
            r = mid
        else:
            l = mid + 1
    # 找到的是第一个大于等于的 可能小于t的哪个数比他更接近 需要判断一下
    if l >= 0 and t - a[l - 1] < a[l] - t:
        print(a[l - 1])
    else:
        print(a[l])
        
    

if __name__ == '__main__':
    solve()