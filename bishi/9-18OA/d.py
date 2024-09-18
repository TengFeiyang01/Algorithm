import heapq

def max_flips(arr):
    flips = 0
    cumulative_sum = 0
    max_heap = []
    
    for x in arr:
        cumulative_sum += x
        # 尝试翻转当前元素
        cumulative_sum -= 2 * x
        heapq.heappush(max_heap, -x)  # 使用最大堆，存储负值
        flips += 1
        
        # 如果累积和小于等于0，撤销之前翻转的最大元素
        if cumulative_sum <= 0:
            if max_heap:
                largest = -heapq.heappop(max_heap)
                cumulative_sum += 2 * largest  # 撤销翻转
                flips -= 1
            else:
                # 无法撤销翻转，累积和无法为正
                return flips

    return flips

# 示例用法：
n = int(input())
PnL = [int(x) for x in input().split()]
max_negative_months = max_flips(PnL)
print(max_negative_months)
