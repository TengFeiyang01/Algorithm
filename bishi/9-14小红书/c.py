import sys
from collections import deque

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())

N = 100005  # 假设最大节点数为 100000
head = [-1] * N  # head[i] 表示以 i 为起点的第一条边的编号
edges = []  # 存储所有边
idx = 0  # 记录边的编号

# 链式前向星添加一条边
def add_edge(u, v, w):
    global idx
    edges.append((v, w, head[u]))  # (终点，权值，下一条边的编号)
    head[u] = idx  # 更新起点 u 的第一条边编号
    idx += 1

def solve() -> None:
    n, q = mint()
    
    # 构建图
    for _ in range(n - 1):
        u, v, w = mint()
        add_edge(u, v, w)
        add_edge(v, u, w)

    f = [0] * (n + 1)  # 用于存储从节点1到每个节点的异或值
    cnt = {}  # 使用字典来统计每个异或值的出现次数

    def bfs(start):
        queue = deque([start])
        cnt[f[start]] = cnt.get(f[start], 0) + 1
        visited = [False] * (n + 1)
        visited[start] = True

        while queue:
            x = queue.popleft()
            i = head[x]
            while i != -1:  # 遍历从 x 出发的所有边
                v, w, next_edge = edges[i]
                if not visited[v]:
                    f[v] = f[x] ^ w  # 更新节点 v 的异或值
                    cnt[f[v]] = cnt.get(f[v], 0) + 1
                    visited[v] = True
                    queue.append(v)
                i = next_edge

    # 从节点1开始广度优先搜索
    bfs(1)

    # 处理查询
    for _ in range(q):
        u, k = mint()
        print(cnt.get(k ^ f[u], 0))

if __name__ == '__main__':
    solve()
