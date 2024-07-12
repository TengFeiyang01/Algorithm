import sys

sys.setrecursionlimit(10000000)
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

class TireNode:
    def __init__(self) -> None:
        self.son = [None] * 2
        self.cnt = 0

rt = TireNode()

def add(x):   
    cur = rt
    for i in range(30, -1, -1):
        u = x >> i & 1
        if not cur.son[u]:
            cur.son[u] = TireNode()
        cur = cur.son[u]
        cur.cnt = 1

def remove(x):
    cur = rt
    for i in range(30, -1, -1):
        u = x >> i & 1
        cur = cur.son[u]
        cur.cnt -= 1

def query(x):
    cur = rt
    res = 0
    for i in range(30, -1, -1):
        u = x >> i & 1
        if cur.son[1 - u] and cur.son[1 - u].cnt:
            res |= 1 << i
            cur = cur.son[1 - u]
        else:
            cur = cur.son[u]
    return res            

def solve():
    n = sint()
    a = ints()
    adj = [[] for _ in range(n)]

    for i, x in enumerate(ints()):
        if x != -1:
            adj[x].append(i)
            adj[i].append(x)
    
    for x in a:
        add(x)
    
    ans = 0
    for i, x in enumerate(a):
        for j in adj[i]:
            remove(a[j])
        ans = max(ans, query(x))
        for j in adj[i]:
            add(a[j])
    print(ans)



if __name__ == '__main__':
    solve()
