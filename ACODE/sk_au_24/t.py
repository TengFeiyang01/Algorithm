def can_travel(n, m, edges, p):
    from collections import defaultdict, deque
    
    # 构建图
    graph = defaultdict(list)
    for i in range(m):
        x, y = edges[i]
        graph[x].append((y, p[i]))
        graph[y].append((x, p[i]))

    # 机器人数量
    f = [None] * (n + 1)
    f[1] = 0  # 城市1购买0个机器人

    # BFS遍历城市
    queue = deque([1])
    visited = set([1])
    
    while queue:
        current = queue.popleft()
        current_robots = f[current]
        
        for neighbor, required in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                # 设定机器人的数量
                # 选择最小的数量，确保与当前城市不同
                if current_robots == 0:
                    f[neighbor] = 1  # 选择1个机器人
                else:
                    f[neighbor] = 0  # 选择0个机器人

                queue.append(neighbor)
            else:
                # 已经访问过的城市
                if f[neighbor] == current_robots:
                    return "No"  # 找到相同数量的情况，返回"No"
    
    return "Yes", f[1:]  # 返回"Yes"和机器人数量

# 输入处理
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    edges = []
    p = []
    for __ in range(m):
        x, y, pi = map(int, input().split())
        edges.append((x, y))
        p.append(pi)

    result = can_travel(n, m, edges, p)
    
    if result == "No":
        print(result)
    else:
        print(result[0])
        print(" ".join(map(str, result[1][1:])))
