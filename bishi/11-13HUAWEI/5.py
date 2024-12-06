def min_cost(writeCpuReq, readCpuReq, memSizeReq, dbPools):
    max_cpu = writeCpuReq + readCpuReq
    max_mem = memSizeReq
    max_cost = float('inf')

    # 初始化DP数组
    dp = [[max_cost] * (max_mem + 1) for _ in range(max_cpu + 1)]
    dp[0][0] = 0

    # 遍历每一个数据库池
    for cpuCores, memSize, price, number in dbPools:
        for _ in range(number):
            for i in range(max_cpu, cpuCores - 1, -1):
                for j in range(max_mem, memSize - 1, -1):
                    dp[i][j] = min(dp[i][j], dp[i - cpuCores][j - memSize] + price)

    min_cost = max_cost
    for i in range(writeCpuReq, max_cpu + 1):
        for j in range(memSizeReq, max_mem + 1):
            min_cost = min(min_cost, dp[i][j])

    return -1 if min_cost == max_cost else min_cost


writeCpuReq = 10
readCpuReq = 8
memSizeReq = 2
dbPools = [
    [8, 4, 2, 2],
    [8, 4, 3, 3],
    [8, 2, 3, 4]
]
result = min_cost(writeCpuReq, readCpuReq, memSizeReq, dbPools)
print(result)