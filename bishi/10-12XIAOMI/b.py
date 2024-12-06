def solve():
    n = int(input())
    a = list(map(int, input().split()))

    f = [[0] * 2 for _ in range(n + 1)]
      
    for i in range(1, n + 1):
        f[i][0] = f[i - 1][0] + a[i - 1]
        if i >= 2:
            f[i][1] = f[i - 1][0] - 2 * a[i - 2] - a[i - 1]
        if i >= 3:
            f[i][0] = max(f[i][0], f[i - 1][1] + a[i - 1])
            f[i][1] = max(f[i][1], f[i - 1][1] + 2 * a[i - 2] - a[i - 1])
    print(max(f[-1]))



if __name__ == "__main__":

    solve()