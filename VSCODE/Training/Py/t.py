from collections import defaultdict
def solve(relations):
    d = defaultdict(int)
    adj = defaultdict(list)

    for relation in relations:
        a, b = relation.split("->")
        d[b] = d.get(b, 0)
        d[a] += 1
        adj[b].append(a)
    
    q = []
    for u in d:
        if d[u] == 0:
            q.append(u)
    ans = []
    while q:
        q.sort()
        t = []

        for u in q:
            ans.append(u)

            for v in adj[u]:
                d[v] -= 1
                if d[v] == 0:
                    t.append(v)
        q = t
    return ans

if __name__ == "__main__":
    relations = input().split()
    ans = solve(relations)
    print(" ".join(ans))
