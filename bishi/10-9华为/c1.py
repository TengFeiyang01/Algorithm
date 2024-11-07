def dfs(x):
    global ans
    if x == m + 1:
        se = set()
        for i in range(1, n + 1):
            se.add(min(a[i], w[i]) / w[i])
        if len(se) == 1:
            ans += 1
        return

    if x + c - 1 <= m:
        # Strategy 1
        tempA1 = a[:]
        for i in range(x, x + c):
            idx = (i - x) % n + 1
            tempA1[idx - 1] += 4
        dfs(x + c)

        # Strategy 2
        tempA2 = a[:]
        for _ in range(c):
            mx = 0
            id = 0
            for j in range(n):
                if w[j + 1] - tempA2[j] > mx:
                    mx = w[j + 1] - tempA2[j]
                    id = j
            tempA2[id] += 4
        dfs(x + c)

        # Strategy 3
        tempA3 = a[:]
        now = 0
        sum_val = 0
        for i in range(x, x + c):
            sum_val += 1
            idx = (now + 1) % n
            tempA3[idx] += 4
            if sum_val >= b[idx + 1]:
                now += 1
                sum_val = 0
        dfs(x + c)

    else:
        # When x to m is less than c
        # Strategy 1
        tempA1 = a[:]
        for i in range(x, m + 1):
            idx = (i - x) % n + 1
            tempA1[idx - 1] += 4
        dfs(m + 1)

        # Strategy 2
        tempA2 = a[:]
        for i in range(x, m + 1):
            mx = 0
            id = 0
            for j in range(n):
                if w[j + 1] - tempA2[j] > mx:
                    mx = w[j + 1] - tempA2[j]
                    id = j
            tempA2[id] += 4
        dfs(m + 1)

        # Strategy 3
        tempA3 = a[:]
        now = 0
        sum_val = 0
        for i in range(x, m + 1):
            sum_val += 1
            idx = (now + 1) % n
            tempA3[idx] += 4
            if sum_val >= b[idx + 1]:
                now += 1
                sum_val = 0
        dfs(m + 1)


if __name__ == '__main__':
    n = int(input())
    b = [0] * (n + 1)
    a = [0] * (n + 1)
    f1 = [0] * (2 * n + 1)
    global ans
    ans = 0

    for i in range(n):
        f1[i] = i + 1
    w = [0] + list(map(int, input().split()))
    b = [0] + list(map(int, input().split()))
    m = int(input()) // 4
    c = int(input())
    dfs(1)
    print(ans)
