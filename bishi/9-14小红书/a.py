import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


from collections import Counter
def solve() -> None:
    n, k = map(int, input().split())
    a = ints()
    ans = 0
    cnt = Counter()
    for x in a:
        ans += cnt[x ^ k]
        print(x, x ^ k, cnt[x ^ k])
        cnt[x] += 1

    print(ans)

if __name__ == '__main__':
    solve()