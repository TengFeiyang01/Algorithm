import sys

# 计算曼哈顿距离
def manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

# 使用深度优先搜索检查是否能在时间 t 内至少引爆 m 个炸弹
def dfs(index, st, n, booms, dist):
    st[index] = True
    for j in range(n):
        if not st[j] and dist[index][j] <= booms[index][3]:
            dfs(j, st, n, booms, dist)

# 检查是否能在时间 t 内引爆至少 m 个炸弹
def check(t, n, m, booms, dist):
    st = [False] * n

    # 找到所有在时间 t 内可以引爆的炸弹，并从每个炸弹开始一次DFS
    for i in range(n):
        if booms[i][2] <= t and not st[i]:
            dfs(i, st, n, booms, dist)

    # 统计已经引爆的炸弹数量
    return sum(st) >= m

def solve():
    T = int(sys.stdin.readline())

    for _ in range(T):
        n, m = map(int, sys.stdin.readline().split())

        booms = []
        dist = [[0] * n for _ in range(n)]

        # 读取所有炸弹的输入数据
        for i in range(n):
            x, y, t, k = map(int, sys.stdin.readline().split())
            booms.append((x, y, t, k))

            # 计算炸弹之间的曼哈顿距离
            for j in range(i):
                dist[i][j] = dist[j][i] = manhattan_distance(booms[i][0], booms[i][1], booms[j][0], booms[j][1])

        l, r = 0, int(1e9)

        # 二分查找最小等待时间
        while l < r:
            mid = (l + r) // 2
            if check(mid, n, m, booms, dist):
                r = mid
            else:
                l = mid + 1

        print(l)

if __name__ == '__main__':
    solve()
