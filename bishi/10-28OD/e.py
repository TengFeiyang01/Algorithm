from collections import *
n = int(input())
g = defaultdict(list)
a = list(map(int, input().split()))
i = p = q = 0
val = defaultdict(int)
pos = defaultdict(int)
while i < n * 2:
    if a[i] == -1:
        j = i + 1
        while j < 2 * n and a[j] != -1:
            pos[p] = j
            val[p] = a[j]
            g[q].append(p)
            p, j = p + 1, j + 1
        q += 1
        i = j
    else:
        val[p] = a[i]
        pos[p] = i
        p, i = p + 1, i + 1
def dfs(x: int) -> int:
    global a
    sum = val[x]
    for y in g[x]:
        sum += dfs(y)      
    a[pos[x]] = sum
    return sum        
dfs(0)
print(*a)
