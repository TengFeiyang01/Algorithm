import sys
from collections import deque, defaultdict

input = sys.stdin.read
data = input().splitlines()

class Edge:
    def __init__(self, to, weight, next_edge=None):
        self.to = to
        self.weight = weight
        self.next_edge = next_edge

def solve():
    index = 0
    n, q = map(int, data[index].split())
    index += 1

    # 初始化链式前向星图
    graph = [None] * n

    for _ in range(n - 1):
        u, v, w = map(int, data[index].split())
        u -= 1
        v -= 1
        index += 1
        # 添加边到链表头部
        graph[u] = Edge(v, w, graph[u])
        graph[v] = Edge(u, w, graph[v])

    # BFS 初始化
    vis = [False] * n
    res = [0] * n
    deq = deque([0])
    vis[0] = True

    while deq:
        cur = deq.popleft()
        current_edge = graph[cur]
        while current_edge:
            v = current_edge.to
            w = current_edge.weight
            if not vis[v]:
                vis[v] = True
                res[v] = res[cur] ^ w
                deq.append(v)
            current_edge = current_edge.next_edge

    # 统计每个异或值的出现次数
    cnt = defaultdict(int)
    for value in res:
        cnt[value] += 1

    # 处理查询
    results = []
    for _ in range(q):
        u, k = map(int, data[index].split())
        u -= 1
        index += 1
        x = res[u]
        result = cnt.get(x ^ k, 0)
        results.append(str(result))

    # 输出结果
    print("\n".join(results))

if __name__ == '__main__':
    solve()
