import sys

# 定义常量
N = 500010

# 读取输入
input = sys.stdin.read
data = input().split()

n = int(data[0])
q = int(data[1])
a = [0] * (2 * N)
pre = [0] * N
tr = [0] * N
seg = []

# 读取数组a
index = 2
for i in range(n):
    a[i] = int(data[index])
    a[i + n] = a[i]
    index += 1

# 读取操作
l, r = 0, 2 * n - 1
for i in range(1, q + 1):
    c = data[index]
    x = int(data[index + 1])
    index += 2
    if c == 'L':
        seg.append((l, l + x - 1, i))
        if l + x > n - 1:
            l = l + x - n
        else:
            l = l + x
    else:
        seg.append((r - x + 1, r, i))
        if r - x <= n - 1:
            r = r - x + n
        else:
            r = r - x

# 排序
seg.sort(key=lambda t: t[1])

# 更新树状数组并计算答案
def lowbit(x):
    return x & -x

def add(x, v):
    while x < N:
        tr[x] += v
        x += lowbit(x)

def sum(x):
    res = 0
    while x > 0:
        res += tr[x]
        x -= lowbit(x)
    return res

ans = [0] * (q + 1)
j = 0
for i in range(q):
    while j < seg[i][1]:
        j += 1
        if pre[a[j]]:
            add(pre[a[j]], -1)
        add(j, 1)
        pre[a[j]] = j
    tmp = sum(seg[i][1]) - sum(seg[i][0] - 1)
    ans[seg[i][2]] = tmp

# 输出答案
sys.stdout.write('\n'.join(map(str, ans[1:])) + '\n')