import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def solution(A):
    ans = A[0]
    for i in range(1, len(A)):
        if A[i] > A[i - 1]:
            ans += A[i] - A[i - 1]
    return ans


def solve() -> None:
    a = ints()
    print(solution(a))

if __name__ == '__main__':
    solve()