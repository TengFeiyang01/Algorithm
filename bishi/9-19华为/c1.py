def get(items, limit):
    dp = [0] * (limit + 1)
    for weight, count in items:
        dp2 = dp[:]
        for j in range(limit + 1):
            if j + weight <= limit:
                dp2[j + weight] = max(dp2[j + weight], dp[j] + count)
        dp = dp2
    return dp

def solve(groups, c):
    inf = float('-inf')
    dp = [inf] * (c + 1)
    dp[0] = 0

    for items in groups:
        dp2 = [inf] * (c + 1)
        ws = get(items, c)
        for j in range(1, c + 1):
            if ws[j] == 0:
                continue
            for k in range(c - j + 1):
                if dp[k] != inf:
                    dp2[k + j] = max(dp2[k + j], dp[k] + ws[j])
        dp = dp2

    result = max(dp)
    return -1 if result == inf else result

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n, m, c = map(int, data[:3])
    groups = [[] for _ in range(n)]
    index = 3
    for _ in range(n * m):
        pid, weight, count = map(int, data[index:index+3])
        groups[pid].append((weight, count))
        index += 3

    result = solve(groups, c)
    print(result)

if __name__ == "__main__":
    main()
