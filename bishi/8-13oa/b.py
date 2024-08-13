import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def solution(digits):
    ans = max(digits)
    n = len(digits)
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                ans = max(ans, digits[i] * 100 + digits[j] * 10 + digits[k])
    return ans    
    


def solve() -> None:
    a = ints()
    print(solution(a))

if __name__ == '__main__':
    solve()