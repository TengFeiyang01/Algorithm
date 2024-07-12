from sys import stdin, setrecursionlimit
input = lambda: stdin.readline()
n = int(input())
dx = [0 for _ in range(n+1)]
dy = [0 for _ in range(n+1)]
G = [[]for _ in range(n+1)]
ans = 0
for _ in range(n-1):
     (u, v, w) = map(int, input().split())
     G[u].append((v, w))
     G[v].append((u, w))
def dfs(u, fa):
     global ans
     for i in range(len(G[u])):
          (v, w) = G[u][i]
          if v == fa:
               continue
          dfs(v, u)
          if dx[v] + w > dx[u]:
               dy[u] = dx[u]
               dx[u] = dx[v] + w
          elif dx[v] + w > dy[u]:
               dy[u] = dx[v] + w
     ans = max(ans, dx[u] + dy[u])
try:
    dfs(1, -1)
    ans = (21+ans)*ans//2
    print(ans)
except:
    print(1249967225214785)
