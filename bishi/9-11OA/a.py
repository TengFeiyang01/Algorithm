import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solution(K, A):
    n, m = len(A), len(A[0])
    cnt = [[0] * (m + 1) for _ in range(n + 1)]
    p = []
    ans = 0
    for i, row in enumerate(A):
        for j, x in enumerate(row):
            if x == 1:
                p.append((i, j))

    for x, y in p:
        l, r = y-K, y+K
        i = x
        while i >= 0 and l <= r:
            cnt[i][max(0, l)] += 1
            cnt[i][min(r+1, m)] -= 1
            i -= 1
            l += 1
            r -= 1

        i = x + 1
        l, r = y-K+1, y+K-1
        while i < n and l <= r:
            cnt[i][max(0, l)] += 1
            cnt[i][min(r+1, m)] -= 1
            i += 1
            l += 1
            r -= 1


    for i in range(n):
        for j in range(m):
            if j:
                cnt[i][j] += cnt[i][j - 1]
            ans += A[i][j] != 1 and cnt[i][j] >= len(p)

    return ans


def solve() -> None:
    n, k = mint()
    print(solution(k, [ints() for _ in range(n)]))


if __name__ == '__main__':
    solve()