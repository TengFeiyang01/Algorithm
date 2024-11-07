from collections import deque

def bfs(start, adj, color, groups):
    q = deque([start])
    color[start] = 0 
    groups[0].append(start) 

    while q:
        u = q.popleft()
        for v in adj[u]:
            if color[v] == -1: 
                color[v] = 1 - color[u]  
                groups[color[v]].append(v) 
                q.append(v)
            elif color[v] == color[u]: 
                return False  
    return True

def find_groups(n, adj):
    color = [-1] * n 
    res = []

    for start in range(n):
        if color[start] == -1: 
            groups = [[] for _ in range(2)] 
            if not bfs(start, adj, color, groups):
                return -1  
            res.append(groups)

    ans1, ans2 = set(), set()
    for groups in res:
        ans1.update(groups[0])
        ans2.update(groups[1])

    ans1 = sorted(ans1)
    ans2 = sorted(ans2)

    return ans1, ans2

if __name__ == "__main__":
    n = int(input())
    adj = []

    for _ in range(n):
        relations = list(map(int, input().strip().split()))
        adj.append(relations)

    result = find_groups(n, adj)
    if result == -1:
        print(-1)
    else:
        group1, group2 = result
        print(' '.join(map(str, group1)))
        print(' '.join(map(str, group2)))
