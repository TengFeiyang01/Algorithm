# D:\Algorithm\bishi\8-22OA\a.py 2024-08-22 by ytf
import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def countInvestablePeriods(price, max_price, min_price):
    n = len(price)
    ans = 0
    min_i = max_i = i0 = -1
    for i, x in enumerate(price):
        if x == min_price: min_i = i
        if x == max_price: max_i = i
        if not min_price <= x <= max_price: i0 = i 
        ans += max(min(min_i, max_i) - i0, 0)
    return ans


def solve() -> None:
    print(countInvestablePeriods(ints(), sint(), sint()))


if __name__ == '__main__':
   solve()