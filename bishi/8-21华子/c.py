import sys
from collections import deque, defaultdict

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def solve():
    n = sint()
    adj = defaultdict(list)
    in_degree = defaultdict(int)
    vertices = set()

    for i in range(n):
        a = ints()
        u = a[1]
        vertices.add(u)
        for v in a[2:]:
            adj[u].append(v)
            in_degree[v] += 1
            vertices.add(v)

    # Kahn's algorithm for Topological Sorting
    zero_in_degree = deque([v for v in vertices if in_degree[v] == 0])
    topo_order = []
    count = 0

    while zero_in_degree:
        u = zero_in_degree.popleft()
        topo_order.append(u)
        count += 1

        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                zero_in_degree.append(v)

    # If count is less than the number of vertices, there is a cycle
    if count < len(vertices):
        print("Cycle detected")
        # Finding the cycle (optional, if required)
        vis = {}
        for u in vertices:
            vis[u] = 0  # 0 = not visited, 1 = visiting, 2 = visited

        cycle = []

        def find_cycle(u):
            vis[u] = 1
            cycle.append(u)
            for v in adj[u]:
                if vis[v] == 1:  # Back edge found
                    cycle.append(v)
                    return True
                if vis[v] == 0 and find_cycle(v):
                    return True
            vis[u] = 2
            cycle.pop()
            return False

        for u in vertices:
            if vis[u] == 0:
                if find_cycle(u):
                    break
        
        # Printing the cycle (if found)
        cycle_start = cycle[-1]
        cycle_output = []
        idx = cycle.index(cycle_start)
        for i in range(idx, len(cycle)):
            cycle_output.append(cycle[i])
        cycle_output.append(cycle_start)
        print("Cycle in the graph:", *cycle_output)
    else:
        print("No cycle detected")
        print("Topological Order:", *topo_order)

if __name__ == '__main__':
    solve()
