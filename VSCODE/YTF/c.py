import sys

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve():
    n = sint()
    a = ints()
    d = {0:1, 4:1, 6:1, 9:1, 8:2, 1:0, 2:0, 3:0, 5:0, 7:0}
    def get(x):
        return sum(d[int(c)] for c in str(x))

    a.sort(key=lambda x:(get(x), x))
    print(*a)            
            


if __name__ == '__main__':
    solve()
