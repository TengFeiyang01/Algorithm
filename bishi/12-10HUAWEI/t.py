from collections import deque, defaultdict

def solve(rules, edges):
    adj = defaultdict(list)
    d = defaultdict(int)
    
    for u, f in rules.items():
        for v in f:
            adj[v].append(u)
            d[u] += 1

    q = deque(edges)
    ans = set(edges)

    while q:
        u = q.popleft()
        for v in adj[u]:
            d[v] -= 1
            if d[v] == 0:
                ans.add(v)
                q.append(v)
    
    return ans

rules = {
    'c': {'a', 'b'},
    'e': {'c', 'd'}
}

a = {'a', 'b', 'd'}
b = {'a', 'b'}

result1 = solve(rules, a)
result2 = solve(rules, b)

print(result1) 
print(result2)