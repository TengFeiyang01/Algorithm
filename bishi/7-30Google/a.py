import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

from collections import *
from heapq import *
def solution(clients):
    h = []
    n = len(clients)
    for i in range(n):
        heappush(h, i + 1)

    d = Counter()
    p = Counter()
    ans = -1
    for u in clients:
        if d[u] == 0:
            ans = heappop(h)
            p[u] = ans
        else:
            heappush(h, p[u])
            del p[u]
        d[u] ^= 1
    return ans

def solve() -> None:
    t = ["Alice","Bob","Bobby"]
    print(solution(["Bob", "bob", "BoB", "bob", "BOB"]))
    print(solution(t))


if __name__ == '__main__':
    solve()