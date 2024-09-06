import sys
import heapq
from collections import Counter

def solve():
    n, m, k, l = map(int, sys.stdin.readline().split())

    g = []
    st = set()

    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        g.append((a, b))
        if a == k or b == k:
            st.add(a)
            st.add(b)

    cnt = Counter()
    for a, b in g:
        if b in st and a not in st:
            cnt[a] += 1
        if a in st and b not in st:
            cnt[b] += 1

    # 使用 heapq 作为优先队列
    pq = [(-v, k) for k, v in cnt.items()]
    heapq.heapify(pq)

    ans = []
    for _ in range(l):
        if pq:
            ans.append(heapq.heappop(pq)[1])
        else:
            ans.append(0)

    print(" ".join(map(str, ans)))

solve()
