n, k = map(int, input().split())
a = list(map(int, input().split()))
from math import inf
from collections import deque

mx = deque()
mn = deque()

ans = []
res = []

for i, x in enumerate(a):
    while mx and x > a[mx[-1]]: mx.pop()
    mx.append(i)
    while mn and x < a[mn[-1]]: mn.pop()
    mn.append(i)
    if i - mx[0] >= k:
        mx.popleft()
    if i - mn[0] >= k:
        mn.popleft()
    if i >= k - 1:
        ans.append(a[mn[0]])
        res.append(a[mx[0]])
print(*ans)
print(*res)