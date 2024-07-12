MOD = 99999997

def lowbit(x):
    return x & -x

def add(x, v):
    while x <= n: # 树状数组的下标是1~n
        tr[x] += v
        x += lowbit(x)

def query(x):
    res = 0
    while x:
        res += tr[x]
        x -= lowbit(x)
    return res

n = int(input())
a = sorted(enumerate(map(int, input().split())), key=lambda x: x[1])
b = sorted(enumerate(map(int, input().split())), key=lambda x: x[1])
tr = [0] * (n + 1)
c = [0] * n

for i in range(n):
    c[a[i][0]] = b[i][0] # 下标映射，相当于以 a[i] 为关键字对序列 b[i] 排序


# 求逆序对
res = 0
for i in range(n - 1, -1, -1): # 树状数组求的是前缀和呀，即比它小的个数，所以得逆序遍历
    res = (res + query(c[i] + 1)) % MOD
    add(c[i] + 1, 1)
print(res)
