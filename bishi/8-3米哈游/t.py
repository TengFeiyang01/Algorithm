import heapq

def min_cost_to_travel(D, P, T):
    n = len(D)
    fuel = 0
    cost = 0
    pq = []  # 使用最小堆来维护油价

    for i in range(n):
        # 补充燃料直到能够到达下一个城市
        while fuel < D[i]:
            if not pq:
                return -1
            price, amount = heapq.heappop(pq)
            fuel_needed = min(T - fuel, D[i] - fuel)
            cost += fuel_needed * price
            fuel += fuel_needed

        # 到达下一个城市，更新燃料量
        fuel -= D[i]

        # 将当前城市的油价和可以加油的量推入堆
        heapq.heappush(pq, (P[i], T))

    return cost

# 示例输入
D = [10, 9, 8]
P = [2, 1, 3]
T = 15

print(min_cost_to_travel(D, P, T))


D = list(map(int, input().split()))
P = list(map(int, input().split()))
T = int(input())
x = min_cost_to_travel(D, P, T)
print(x)