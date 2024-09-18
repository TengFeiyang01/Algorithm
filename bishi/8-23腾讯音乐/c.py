def solve(arr, m):
    res = 0
    n = len(arr)

    min_val = min(arr)
    max_val = max(arr)

    for i in range(n - 1):
        res += abs(arr[i] - arr[i + 1])

    if min_val > 1:
        res += min((min_val - 1) * 2, min(arr[0] - 1, arr[-1] - 1))

    if m > max_val:
        res += min((m - max_val) * 2, min(m - arr[0], m - arr[-1]))

    return res
