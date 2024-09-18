import sys
import heapq
input = sys.stdin.readline


if __name__ == '__main__':
    n = int(input())
    nums_list = list(map(int, input().split()))
    sub_list = list(map(int, input().split()))
    cost_list = list(map(int, input().split()))
    t = int(input())
    ans = 0
    todo_time = t
    temp_list = []
    cost_sum = 0
    # 数据范围较小，枚举最后在每个池塘的情况，使用优先队列每次选取前面时间内最大值
    for i in range(1, n + 1):
        res = 0
        if cost_sum >= t:
            break
        for j in range(1, i + 1):
            temp_list.append((-nums_list[j - 1], j))
        heapq.heapify(temp_list)
        surplus = t - cost_sum
        for m in range(1, surplus + 1):
            num, idx = heapq.heappop(temp_list)
            num = -num
            if num <= 0:
                break
            res += num
            heapq.heappush(temp_list, (-(num - sub_list[idx - 1]), idx))
        if i != n:
            cost_sum += cost_list[i - 1]
        ans = max(ans, res)
    print(ans)

