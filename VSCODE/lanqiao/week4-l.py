import sys
import heapq
from itertools import*
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    n = sint()
    ans = 0
    for seq in permutations(nums):
        digits = list(seq)
        integer = 0
        for i in range(7):
            integer = 10*integer + digits[i]
            numerator = 0
            for j in range(i + 1, 8):
                numerator = 10*numerator + digits[j]
                denominator = 0
                for k in range(j + 1, 9):
                    denominator = 10*denominator + digits[k]
                if numerator % denominator == 0:
                    if integer + numerator // denominator == n:
                        ans += 1


if __name__ == '__main__':
    solve()