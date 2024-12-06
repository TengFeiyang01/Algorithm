import sys
from collections import defaultdict

# 设置递归深度限制
sys.setrecursionlimit(100000)

def add(adj_list, l, r):
    adj_list[l].append(r)

def dfs(adj_list, a, u, f):
    sum_ = 0
    for j in adj_list[u]:
        if j == f:  # 忽略父节点
            continue
        k = dfs(adj_list, a, j, u)
        if k > 0:
            sum_ += k
    return sum_ + a[u]

def main():
    input = sys.stdin.read
    data = input().split()

    idx = 0
    n = int(data[idx])
    idx += 1

    adj_list = defaultdict(list)

    for i in range(1, n):
        k = int(data[idx])
        idx += 1
        add(adj_list, k, i + 1)

    a = [0] * (n + 1)

    for i in range(1, n + 1):
        a[i] = int(data[idx])
        idx += 1

    for i in range(1, n + 1):
        a[i] += int(data[idx])
        idx += 1

    print(max(0, dfs(adj_list, a, 1, -1)))

if __name__ == "__main__":
    main()