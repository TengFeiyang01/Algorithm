import heapq

class Pair:
    def __init__(self, t, w):
        self.t = t
        self.w = w

    def __lt__(self, other):
        return self.t < other.t

def solve():
    n = int(input())
    
    a = []
    for _ in range(n):
        t, w = map(int, input().split())
        a.append(Pair(t, w))

    # 对 (t, w) 对进行排序
    a.sort()

    i = 0
    ans = 0
    cur = a[0].t
    
    # 使用优先队列作为最小堆，存储 (w, t) 对
    h = []

    while i < n:
        # 将所有 t <= cur 的 (w, t) 对入堆
        while i < n and a[i].t <= cur:
            heapq.heappush(h, (a[i].w, a[i].t))
            i += 1

        if not h:
            cur = a[i].t
            while i < n and a[i].t <= cur:
                heapq.heappush(h, (a[i].w, a[i].t))
                i += 1

        if i == n:
            break

        # 处理堆中的数据
        while h and h[0][0] + cur <= a[i].t:
            cur += h[0][0]
            ans += cur - h[0][1]
            heapq.heappop(h)

        if h and h[0][0] + cur > a[i].t:
            top = heapq.heappop(h)
            heapq.heappush(h, (top[0] - (a[i].t - cur), top[1]))
            cur = a[i].t

    # 处理剩下的堆中的数据
    while h:
        cur += h[0][0]
        ans += cur - h[0][1]
        heapq.heappop(h)

    print(ans)

if __name__ == "__main__":
    solve()
