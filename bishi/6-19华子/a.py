import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = sint()
    a = ints()
    for i in range(n):
        x = 0
        while a[i]:
            x *= 2
            if a[i] & 1:
                x += 1
            a[i] //= 2
        a[i] = x
    print(*a[::-1])

if __name__ == '__main__':
    solve()