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
def next_state(input_state):
    # 获取输入状态的行数和列数
    rows = len(input_state)
    cols = len(input_state[0]) if rows > 0 else 0
    
    # 初始化一个与输入状态相同大小的矩阵，用于存储下一个状态
    # 更新答案的时候更新这里，已经计算的不会影响之后的
    pre, cur, next = [], [], [] # 3个一维数组来记录3行数组，上一行，当前行，下一行

    pre = input_state[(-1)%rows][:]
    cur = input_state[0][:]
    if rows > 1:
        next = input_state[1][:]

    base = input_state[0][::]
    
    # 遍历每个神经元
    for i in range(rows):
        for j in range(cols):
            current_strength = cur[j]  # 获取当前神经元的强度
            active_neighbors = 0  # 计数激活邻居的数量
            # 计算放电的邻居数量
            
            for nj in [j-1, j, j+1]:
                if pre[nj % cols] > 0:
                    active_neighbors += 1
            for nj in [j-1, j+1]:
                if cur[nj % cols] > 0 :
                    active_neighbors += 1
            for nj in [j-1, j, j+1]:
                if next[nj % cols] > 0:
                    active_neighbors += 1
                        
            if current_strength == 0:
                if active_neighbors == 3:
                    input_state[i][j] = 6
                else:
                    input_state[i][j] = 0
            else:
                if active_neighbors <= 1:
                    # 和0取max确保强度不为负数
                    input_state[i][j] = max(0, current_strength - 2)  # 镇静，强度降低2
                elif active_neighbors > 3:
                    # 和0取max确保强度不为负数
                    input_state[i][j] = max(0, current_strength - 1)  # 镇静，强度降低1
                else:
                    input_state[i][j] = current_strength  # 强度不变
        pre = cur[:]
        cur = next[:]
        if i + 2 < rows:
            next = input_state[i + 2][:]
        else:
            next = base
    return input_state  # 返回计算得到的下一个状态


def solve() -> None:
    n = sint()
    grid = [ints() for _ in range(n)]
    new_grid = next_state(grid)
    for row in new_grid:
        print(row)

if __name__ == '__main__':
    solve()