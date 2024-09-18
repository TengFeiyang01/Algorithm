from collections import deque, defaultdict

def calculate_influence(n, m, k, connections):
    # 构建社交网络图
    graph = defaultdict(list)
    for x, y in connections:
        graph[x].append(y)
        graph[y].append(x)

    # 广度优先搜索（BFS）计算影响力
    queue = deque([(m, 0)])  # 队列存储节点和距离
    visited = set([m])
    influence_count = 0

    while queue:
        node, depth = queue.popleft()
        if depth < k:
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, depth + 1))
                    influence_count += 1

    return influence_count

# 输入处理
def main():
    n, m, k = map(int, input().split())
    connections = [tuple(map(int, input().split())) for _ in range(n)]
    influence = calculate_influence(n, m, k, connections)
    print(influence)

if __name__ == "__main__":
    main()
