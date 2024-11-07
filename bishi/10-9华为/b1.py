import sys
from heapq import heappush, heappop

MAX_N = 21000 
arr = [0] * MAX_N  
deg = [0] * MAX_N 
g = [[] for _ in range(MAX_N)]  
dp = [0] * MAX_N 

def main():
    n = int(input().strip())

    arr = list(map(int, input().split()))

    # 初始化入度数组
    for i in range(n):
        deg[i] = 0

    # 输入邻接边
    for i in range(n):
        line = sys.stdin.readline().strip()
        if line:
            neighbors = map(int, line.split())
            for v in neighbors:
                if v == -1:
                    break
                g[v - 1].append(i)  # 有向边从 v-1 指向 i
                deg[i] += 1  # 增加入度

    # 优先队列，存储 (路径和, 节点)
    pp = []

    # 将所有入度为0的节点入队
    for i in range(n):
        if deg[i] == 0:
            heappush(pp, (arr[i], i))
            dp[i] = arr[i]  # 初始化动态规划值

    # 拓扑排序处理
    while pp:
        cur_val, u = heappop(pp)

        for v in g[u]:
            deg[v] -= 1
            if deg[v] == 0:
                dp[v] = dp[u] + arr[v]
                heappush(pp, (dp[v], v))

    # 输出最大权值和
    print(max(dp[:n]))

if __name__ == "__main__":
    main()