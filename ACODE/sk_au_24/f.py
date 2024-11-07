def can_balance(n, m, a, b, friendships):
    from collections import defaultdict, deque
    
    graph = defaultdict(list)
    
    # 构建图
    for x, y in friendships:
        graph[x - 1].append(y - 1)
        graph[y - 1].append(x - 1)

    visited = [False] * n
    for i in range(n):
        if not visited[i]:
            queue = deque([i])
            visited[i] = True
            total_initial = 0
            total_target = 0
            
            while queue:
                node = queue.popleft()
                total_initial += a[node]
                total_target += b[node]
                
                for neighbor in graph[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append(neighbor)
            
            if total_initial != total_target:
                return "No"
    
    return "Yes"

T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    friendships = [tuple(map(int, input().split())) for _ in range(m)]
    
    result = can_balance(n, m, a, b, friendships)
    print(result)
