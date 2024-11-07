import sys

def find_min_max_execution_time(arr):
    sum_total = sum(arr)
    target = sum_total / 7

    n = len(arr)
    start = 0
    tot = 0

    l = None
    r = None
    ldiff = float('inf')
    rdiff = float('inf')

    min_f = float('inf')

    for end in range(n):
        tot += arr[end]

        while tot > target and start <= end:
            diff = tot - target
            if diff < rdiff:
                rdiff = diff
                r = tot

            tot -= arr[start]
            start += 1

        diff = abs(tot - target)
        if tot <= target and (target - tot) < ldiff:
            ldiff = target - tot
            l = tot

    res = []
    if l is not None:
        res.append(max(6 * l, sum_total - l))
    if r is not None:
        res.append(max(6 * r, sum_total - r))

    if res:
        min_f = min(res)
    else:
        min_f = sum_total

    return int(min_f)

def main():

    n = int(input())
    arr = list(map(int, input().split()))

    result = find_min_max_execution_time(arr)
    print(result)

if __name__ == "__main__":
    main()
