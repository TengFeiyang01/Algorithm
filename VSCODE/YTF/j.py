# E:\0CODE\VSCODE\YTF\j.py 2024-04-21 by ytf
import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = 51
    tot = 0
    ans = 0
    # [1, 2, 3, 4, 5, 6]
    # [1, 5, 3, 4, 2, 6]
    cur = list(range(52))

    for i in range(1, 52):
        for j in range(1, 52):
            if i != j:
                tot += 1
                ans += abs(i- j) + abs(i - j)-1
                now = 0
    res = 0
    for i in range(1, 52):
        for j in range(1, 52):
            if i != j:
                cur[i], cur[j] = cur[j], cur[i]
                for p in range(1, 52):
                    for q in range(1, 52):
                        if p < q and cur[p] > cur[q]:
                            res += 1
                cur[i], cur[j] = cur[j], cur[i]

    print(res, ans)
    print(ans / tot)

if __name__ == '__main__':
    solve()