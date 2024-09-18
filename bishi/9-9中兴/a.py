from collections import defaultdict
import heapq

def find_busiest_servers(k, m, n):
    servers = [0] * k 
    tasks_count = [0] * k 

    for i in range(len(m)):
        start = i % k
        assigned = False
        for j in range(k):
            idx = (start + j) % k
            if servers[idx] <= m[i]:
                servers[idx] = m[i] + n[i]
                tasks_count[idx] += 1
                assigned = True
                break
        if not assigned:
            continue

    max_tasks = max(tasks_count)
    busiest_servers = [i for i in range(k) if tasks_count[i] == max_tasks]

    return busiest_servers

k, m_str, n_str = input().split(' ')
k = int(k)
m = list(map(int, m_str.split(',')))
n = list(map(int, n_str.split(',')))

busiest_servers = find_busiest_servers(k, m, n)
print(','.join(map(str, busiest_servers)))
