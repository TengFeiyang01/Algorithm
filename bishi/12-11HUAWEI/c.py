def solve() -> None:
    n = int(input())
    s = input().split()
    a = [list(map(int, x.split(','))) for x in s]
    m = int(input())
    threshold = int(input())
    limit = int(input())
    cnt = ans = 0
    l = 0
    a.sort(key=lambda x: x[1])
    s = [0] * (n + 1)
    for i, x in enumerate(a, 1):
        if x[0] >= threshold:
            s[i] = 1
    for i in range(1, n + 1):
        s[i] += s[i - 1]
    
    b = [x[1] for x in a]
    from bisect import bisect_left, bisect_right
    for i, x in enumerate(a, 1):
        j = bisect_right(b, x[1]-m)
        if s[i] - s[j] >= limit:
            ans += 1
    print(ans)

if __name__ == '__main__':
    solve()