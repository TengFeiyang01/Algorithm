class KnapsackSolver:
    def __init__(self, capacity):
        self.capacity = capacity
        self.inf = float('-inf')

    def solve_group(self, items):
        dp = [0] * (self.capacity + 1)
        for weight, count in items:
            dp2 = dp[:]
            for j in range(self.capacity + 1):
                if j + weight <= self.capacity:
                    dp2[j + weight] = max(dp2[j + weight], dp[j] + count)
            dp = dp2
        return dp

    def solve_all(self, groups):
        dp = [self.inf] * (self.capacity + 1)
        dp[0] = 0

        for items in groups:
            dp2 = [self.inf] * (self.capacity + 1)
            ws = self.solve_group(items)
            for j in range(1, self.capacity + 1):
                if ws[j] == 0:
                    continue
                for k in range(self.capacity - j + 1):
                    if dp[k] != self.inf:
                        dp2[k + j] = max(dp2[k + j], dp[k] + ws[j])
            dp = dp2

        result = max(dp)
        return -1 if result == self.inf else result

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n, m, c = map(int, data[:3])
    groups = [[] for _ in range(n)]
    index = 3
    for _ in range(n * m):
        pid, weight, count = map(int, data[index:index+3])
        groups[pid].append((weight, count))
        index += 3

    solver = KnapsackSolver(c)
    result = solver.solve_all(groups)
    print(result)

if __name__ == "__main__":
    main()
