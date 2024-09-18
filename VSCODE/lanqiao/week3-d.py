import sys

n, m, q = map(int, input().split())
s = [[0 for i in range(m+1)]]
for i in range(n):
    s += [[0] + list(map(int, input().split()))]

b = [[0 for i in range(m+2)] for j in range(n+2)]
for i in range(1, n+1):
    for j in range(1, m+1):
        b[i][j] = s[i][j] - s[i-1][j] - s[i][j-1] + s[i-1][j-1]

ops = [list(map(int, _.split())) for _ in sys.stdin.readlines()]

for i in range(q):
    x1, y1, x2, y2, c = ops[i]
    b[x1][y1] += c
    b[x2+1][y1] -= c
    b[x1][y2+1] -= c
    b[x2+1][y2+1] += c

for i in range(1, n+1):
    for j in range(1, m+1):
        b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1]
        print(b[i][j], end=' ')
    print()
