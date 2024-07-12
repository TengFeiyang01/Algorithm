# 多路归并可以看坐N - 1次两路归并
from heapq import heappush, heappop

def merge():
    global a
    c = [0] * n
    q = []
    for i in range(n):
        heappush(q, [b[i] + a[0], 0]) # 第一个是值，第二个是a中的下标
    i = 0
    while i < n:
        v, idx = heappop(q)
        c[i] = v
        if idx < n - 1:
            heappush(q, [v - a[idx] + a[idx + 1], idx + 1]) # 太牛了，往后移动
        i += 1

    a[:n] = c[:n]


T = int(input())
while T:
    m, n = map(int, input().split())
    a = sorted(map(int, input().split()))

    for _ in range(m - 1):
        b = list(map(int, input().split()))
        merge()

    print(*a)
    T -= 1