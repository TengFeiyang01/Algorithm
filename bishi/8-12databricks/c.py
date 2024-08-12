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

def solution(board):
    n, m = len(board), len(board[0])
    
    for i in range(n):
        pre = cnt = 0
        for j in range(m):
            if board[i][j] == '#':
                cnt += 1
            elif board[i][j] == '*':
                p = j - 1
                while p >= pre:
                    if cnt > 0:
                        cnt -= 1
                        board[i][p] = '#'
                    else:
                        board[i][p] = '-'
                    p -= 1
                pre = j + 1
        if cnt:
            p = m - 1
            while p >= pre:
                if cnt > 0:
                    cnt -= 1
                    board[i][p] = '#'
                else:
                    board[i][p] = '-'  
                p -= 1

    for i in range(m):
        cnt = pre = 0
        for j in range(n):
            if board[j][i] == '#':
                cnt += 1
            elif board[j][i] == '*':
                p = j - 1
                while p >= pre:
                    if cnt > 0:
                        cnt -= 1
                        board[p][i] = '#'
                    else:
                        board[p][i] = '-'
                    p -= 1
                cnt = 0
                pre = j + 1
            
        if cnt:
            p = n - 1
            while p >= pre:
                if cnt > 0:
                    board[p][i] = '#'
                    cnt -= 1
                else:
                    board[p][i] = '-'
                p -= 1
            cnt = 0
    return board


def solve() -> None:
    n = sint()
    a = [list(input().split()) for _ in range(n)]
    print(solution(a))

if __name__ == '__main__':
    solve()