from collections import defaultdict
import heapq

def find_busiest_servers(k, m, n):
    servers = [0] * k  # 记录每个服务器的结束时间
    tasks_count = [0] * k  # 记录每个服务器处理的任务数量

    for i in range(len(m)):
        # 找到可以处理任务的服务器
        start = m[i] % k
        assigned = False
        for j in range(k):
            idx = (start + j) % k
            if servers[idx] <= m[i]:
                servers[idx] = m[i] + n[i]
                tasks_count[idx] += 1
                assigned = True
                break
        
        # 如果所有服务器都忙，任务被丢弃，不做任何操作
        if not assigned:
            continue

    max_tasks = max(tasks_count)
    busiest_servers = [i for i in range(k) if tasks_count[i] == max_tasks]

    return busiest_servers

# 读取输入
k, m_str, n_str = input().split(',')
k = int(k)
m = list(map(int, m_str.split()))
n = list(map(int, n_str.split()))

# 查找最繁忙的服务器
busiest_servers = find_busiest_servers(k, m, n)
print(','.join(map(str, busiest_servers)))
