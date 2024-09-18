if True:
    def maximalRectangle(matrix):
        if not matrix or not matrix[0]:
            return 0

        n, m = len(matrix), len(matrix[0])
        
        # 构建前缀和矩阵
        prefix = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]
        
        # 计算每列的高度
        height = [[0] * (m + 2) for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if matrix[i][j] > 0:
                    height[i][j + 1] = height[i - 1][j + 1] + 1 if i > 0 else 1
        
        # 计算最大子矩阵和
        max_sum = float('-inf')
        for i in range(n):
            stack = []
            for j in range(m + 2):
                while stack and height[i][stack[-1]] > height[i][j]:
                    h = height[i][stack.pop()]
                    w = j - stack[-1] - 1
                    if h > 0:
                        # 计算子矩阵和
                        sum_submatrix = self.calculate_sum(prefix, i, stack[-1] + 1, j - 1, h)
                        max_sum = max(max_sum, sum_submatrix)
                stack.append(j)
        
        return max_sum

    def calculate_sum(self, prefix, bottom, left, right, height):
        top = bottom - height + 1
        return prefix[bottom + 1][right + 1] - prefix[top][right + 1] - prefix[bottom + 1][left] + prefix[top][left]

# 示例输入
matrix = [
    [1, 0, 5, 0, 0],
    [0, 1, 2, 1, 1],
    [0, 1, 1, 1, 1],
    [0, 0, 5, 0, 0]
]

print(maximalRectangle(matrix))  # 输出最大的子矩阵和
