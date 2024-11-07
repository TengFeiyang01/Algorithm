MOD = 998244353

def mod(x):
    return x % MOD

def solve(f, n, k):
    print(f[n][k])

def main():
    N = 3005
    f = [[0] * (N * 2) for _ in range(N)]
    f[0][0] = 1

    for i in range(1, N):
        for j in range(i, 0, -1):
            f[i][j] = mod(f[i - 1][j - 1] + f[i][j * 2])

    T = int(input())
    for _ in range(T):
        n, k = map(int, input().split())
        solve(f, n, k)

if __name__ == "__main__":
    main()
