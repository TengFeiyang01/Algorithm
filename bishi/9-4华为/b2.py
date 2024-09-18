import heapq
from collections import Counter
import sys

RI = lambda: map(int, sys.stdin.readline().split())

def solve():
    n, m, k, l = RI()
    g = []
    fs = set()
    for _ in range(m):
        a, b = RI()
        if a == k or b == k:
            fs.add(a)
            fs.add(b)
        g.append((a, b))
    
    c = Counter()
    for a, b in g:
        if a not in fs and b in fs:
            c[a] += 1
        if b not in fs and a in fs:
            c[b] += 1

    # 使用堆来获取前 l 大的元素
    heap = []
    for key, value in c.items():
        heapq.heappush(heap, (-value, key))  # 使用负值来实现最大堆

    ans = []
    for _ in range(l):
        if heap:
            ans.append(heapq.heappop(heap)[1])
        else:
            ans.append(0)

    print(*ans)

solve()
