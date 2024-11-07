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


def dfs(node, good_relations, color, groups):
    groups[color[node]].append(node) 
    for neighbor in good_relations[node]:
        if color[neighbor] == -1: 
            color[neighbor] = 1 - color[node] 
            if not dfs(neighbor, good_relations, color, groups): 
                return False
        elif color[neighbor] == color[node]: 
            return False
    return True

def find_groups(n, good_relations):
    color = [-1] * n  # -1: 未着色
    all_groups = []

    for start in range(n):
        if color[start] == -1:  # 如果当前节点未着色
            groups = [[] for _ in range(2)]  # 初始化两个组
            color[start] = 0  # 着色为组1
            if not dfs(start, good_relations, color, groups):
                return -1  # 无法分成两组
            all_groups.append(groups)

    # 合并所有分组
    final_group1, final_group2 = set(), set()
    for groups in all_groups:
        final_group1.update(groups[0])
        final_group2.update(groups[1])

    # 将分组转换为排序后的列表
    final_group1 = sorted(final_group1)
    final_group2 = sorted(final_group2)

    return final_group1, final_group2


def solve() -> None:
    n = int(input())
    g = [[] for _ in range(n)]
    for i in range(n):
        g[i] = list(map(int, input().split()))
        
    st = [-1] * n
    ans = []
    for i in range(n):       
        if st[i] == -1:
            tmp = [[] for _ in range(2)]
            if not dfs(i, g, st, tmp):
                print(-1)
                return
            ans.append(tmp)
    p, q = set(), set()
    for x, y in ans:
        p.update(x)
        q.update(y)
    
    print(*sorted(p))            
    print(*sorted(q))            

if __name__ == '__main__':
    solve()