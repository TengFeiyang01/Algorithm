def solve():
    n = int(input())

    a = [] 
    while True:
        try:
            offset, size = map(int, input().split())
            a.append([offset, size])
        except:
            break

    if n <= 0 or n > 100:
        return -1

    ans = -1
    min_n = 100

    a.sort()

    cur = 0

    for used in a:
        if used[0] < cur or used[0] > 99:
            print(-1)
            return

        if used[1] <= 0 or used[1] > 100 - used[0]:
            print(-1)
            return
        if used[0] > cur:
            cur_size = used[0] - cur

            if n <= cur_size < min_n:
                ans = cur
                min_n = cur_size

        cur = used[0] + used[1]

    last = 100 - cur
    if n <= last < min_n:
        ans = cur

    print(ans)

if __name__ == '__main__':
    solve()