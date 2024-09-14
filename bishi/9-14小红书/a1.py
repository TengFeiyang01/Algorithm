import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

from collections import defaultdict
def solve() -> None:
    n, k = map(int, input().split())
    cnt = defaultdict(int)
    ans = 0
    for x in map(int, input().split()):
        ans += cnt[k ^ x]
        cnt[x] += 1
    print(ans)


if __name__ == '__main__':
    solve()